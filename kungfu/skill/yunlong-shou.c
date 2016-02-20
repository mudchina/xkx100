// yunlongshou.c -云龙手
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"GRN"「草木皆兵」"NOR"，十指伸缩，虚虚实实地袭向$n的全身要穴",
	"lvl" : 0,
	"skill_name" : "草木皆兵"
]),
([	"action" : "在呼呼风声中，$N使一招"BLU"「捕风捉影」"NOR"，双手如钩如戢，插向$n的$l",
	"lvl"   : 20,
	"skill_name" : "捕风捉影" 
]),
([	"action" : "$N双拳挥舞，一式"CYN"「浮云去来」"NOR"，两手环扣，拢成圈状，猛击$n的下颌",
	"lvl" : 30,
	"skill_name" : "浮云去来"
]),
([	"action" : "$N双手平伸，十指微微上下抖动，一招"YEL"「十指乾坤」"NOR"打向$n的$l",
	"lvl"   : 40,
	"skill_name" : "十指乾坤" 
]),
([	"action" : "$N左手护胸，腋下含空，右手五指如钩，一招"MAG"「抱残守缺」"NOR"插向$n的顶门",
	"lvl"   : 50,
	"skill_name" : "抱残守缺" 
]),
([	"action" : "$N右腿斜插$n二腿之间，一招"RED"「掏虚抢珠」"NOR"，上手取目，下手反勾$n的裆部",
	"lvl"   : 60,
	"skill_name" : "掏虚抢珠" 
]),
([	"action" : "$N一手虚指$n的剑诀，一招"HIC"「空手入刃」"NOR"，劈空抓向$n手中的兵刃",
	"lvl"   : 70,
	"skill_name" : "空手入刃" 
]),
([	"action" : "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招"HIY"「降龙伏虎」"NOR"使$n进退两难",
	"lvl"   : 80,
	"skill_name" : "降龙伏虎" 
]),
([	"action" : "$N一手顶天成爪，一手指地，一招"HIR"「拨云见日」"NOR",劲气笼罩$n的全身",
	"lvl"   : 90,
	"skill_name" : "拨云见日" 
]),
([	"action" : "$N一式"HIM"「如烟往事」"NOR"，拳招若隐若现，若有若无，缓缓地拍向$n的丹田",
	"lvl" : 100,
	"skill_name" : "如烟往事"
]),
([	"action" : "$N随意挥洒，使一式"HIR"「我心依旧」"NOR"，掌心微红,徐徐拍向$n的$l",
	"lvl" : 80,
	"skills_name" : "我心依旧"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yunlong-zhua"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练云龙手必须空手。\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 50)
		return notify_fail("你的云龙神功火候不够，无法学云龙手。\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候不够，无法学云龙手。\n");
	if ((int)me->query("max_neili") < 250)
		return notify_fail("你的内力太弱，无法练云龙手。\n");
	if ((int)me->query_skill("hand",1) <30)
		return notify_fail("你的基本手法火候不够，无法学云龙手。\n");
	if ((int)me->query_skill("yunlong-xinfa")<100 && 2*(int)me->query_skill("yunlong-xinfa",1) <(int)me->query_skill("yunlong-shou",1))
		return notify_fail("你的云龙心法火候不够，无法继续学云龙手。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练云龙手。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -25);
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
	int d_e1 = -45;
	int d_e2 = -15;
	int p_e1 = 15;
	int p_e2 = 45;
	int f_e1 = 140;
	int f_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yunlong-shou", 1);
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
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { 
	if ((int)me->query_skill("yunlong-xinfa",1) < 100)
	return 0.7; 
	else if ((int)me->query_skill("yunlong-xinfa",1) > 200)
	return 1.4;
	else return ( ((int)me->query_skill("yunlong-xinfa",1)-100)/100*0.7+0.7 );
}

string perform_action_file(string action)
{
	return __DIR__"yunlong-shou/" + action;
}
int help(object me)
{
	write(HIC"\n云龙手："NOR"\n");
	write(@HELP

    天地会云龙门武功。
    可与云龙爪互备。

	学习要求：
		基本手法30级
		基本内功50级
		云龙神功50级
		内力250
		相应的云龙心法
HELP
	);
	return 1;
}

