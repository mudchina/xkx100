// yunlong-zhua.c -云龙爪
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N全身拔地而起，半空中一个筋斗，一式"HIM"「凶鹰袭兔」"NOR"，迅猛地抓向$n的$l",
	"lvl"    : 0,
	"skills_name" : "凶鹰袭兔",
]),
([	"action" : "$N单腿直立，双臂平伸，一式"GRN"「雄鹰展翅」"NOR"，双爪一前一后拢向$n的$l",
	"lvl"    : 10,
	"skills_name" : "雄鹰展翅",
]),
([	"action" : "$N一式"HIG"「拔翅鹰飞」"NOR"，全身向斜里平飞，右腿一绷，双爪搭向$n的肩头",
	"lvl"    : 20,
	"skills_name" : "拔翅鹰飞",
]),
([	"action" : "$N双爪交错上举，使一式"HIC"「迎风振翼」"NOR"，一拔身，分别袭向$n左右腋空门",
	"lvl"    : 30,
	"skills_name" : "迎风振翼",
]),
([	"action" : "$N全身滚动上前，一式"HIW"「飞龙献爪」"NOR"，右爪突出，鬼魅般抓向$n的胸口",
	"lvl"    : 40,
	"skills_name" : "飞龙献爪",
]),
([	"action" : "$N伏地滑行，一式"HIY"「顶天立地」"NOR"，上手袭向膻中大穴，下手反抓$n的裆部",
	"lvl"    : 50,
	"skills_name" : "顶天立地",
]),
([	"action" : "$N左右手掌爪互逆，一式"HIW"「搏击长空」"NOR"，无数道劲气破空而出，迅疾无比地击向$n",
	"lvl"    : 60,
	"skills_name" : "搏击长空",
]),
([	"action" : "$N腾空高飞三丈，一式"YEL"「鹰扬万里」"NOR"，天空中顿时显出一个巨灵爪影，缓缓罩向$n",
	"lvl"    : 60,
	"skills_name" : "鹰扬万里",
]),
([	"action" : "$N忽的拨地而起，使一式"BLU"「苍龙出水」"NOR"，身形化作一道闪电射向$n",
	"lvl"    : 70,
	"skills_name" : "苍龙出水",
]),
([	"action" : "$N微微一笑，使一式"HIY"「万佛朝宗」"NOR"，双手幻出万道金光,直射向$n的$l",
	"lvl"    : 80,
	"skills_name" : "万佛朝宗",
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yunlong-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练云龙爪必须空手。\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 50)
		return notify_fail("你的云龙神功火候不够，无法学云龙爪。\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候不够，无法学云龙爪。\n");
	if ((int)me->query("max_neili") < 350)
		return notify_fail("你的内力太弱，无法练云龙爪。\n");
	if ((int)me->query_skill("claw",1) <40)
		return notify_fail("你的基本爪法火候不够，无法学云龙爪。\n");
  if ((int)me->query_skill("yunlong-xinfa")<100 &&
     2*(int)me->query_skill("yunlong-xinfa",1) <
		  (int)me->query_skill("yunlong-zhua",1))
		return notify_fail("你云龙心法火候不够，无法继续学云龙爪。\n"); 
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练云龙爪。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 40;
	int d_e2 = 10;
	int p_e1 = -15;
	int p_e2 = -40;
	int f_e1 = 250;
	int f_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("yunlong-zhua", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "内伤" : "抓伤",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { 
	if ((int)me->query_skill("yunlong-xinfa",1) < 100)
	return 0.7; 
	else if ((int)me->query_skill("yunlong-xinfa",1) > 200)
	return 1.4;
	else return ( ((int)me->query_skill("yunlong-xinfa",1)-100)/100*0.7+0.7 );
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if(me->query_skill("yunlong-shengong",1) > 70 )
	{
		if( random(me->query_skill("yunlong-zhua",1)) > 30 )
		{
			victim->apply_condition("zhua_poison", random(me->query_skill("ningxue-shenzhua",1)/10) + 1 +
			victim->query_condition("zhua_poison"));
		}
	}
}

string perform_action_file(string action)
{
	return __DIR__"yunlong-zhua/" + action;
}
int help(object me)
{
	write(HIC"\n云龙爪："NOR"\n");
	write(@HELP

    天地会云龙门武功，陈近南成名绝技，凝血神抓威震江湖，宵
小之辈望风披靡。
    可与云龙手互备。

	学习要求：
		基本爪法40级
		基本内功50级
		云龙神功50级
		内力350
		相应的云龙心法
HELP
	);
	return 1;
}

