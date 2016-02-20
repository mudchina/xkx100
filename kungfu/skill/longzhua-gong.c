// longzhua-gong.c 龙爪功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "在呼呼风声中，$N使一招"GRN"「捕风式」"NOR"，双手如钩如戢，插向$n的$l",
	"lvl"    : 0,
	"skill_name" : "捕风式" ,
]),
([	"action" : "$N猛地向前跃出，一招"HIB"「捉影式」"NOR"，两腿踢出，双手抓向$n的面门",
	"lvl"    : 6,
	"skill_name" : "捉影式" ,
]),
([	"action" : "$N双手平伸，十指微微上下抖动，一招"HIC"「抚琴式」"NOR"打向$n的$l",	
	"lvl"    : 12,
	"skill_name" : "抚琴式" ,
]),
([	"action" : "$N左手上拦，右手内挥，一招"RED"「击鼓式」"NOR"击向$n胸口",
	"lvl"    : 18,
	"skill_name" : "击鼓式" ,
]),
([	"action" : "$N右手虚握，左手掌立如山，一招"HIM"「批亢式」"NOR"，猛地击向$n的$l",
	"lvl"    : 24,
	"skill_name" : "批亢式" ,
]),
([	"action" : "$N腾步上前，左手护胸，右手探出，一招"YEL"「掏虚式」"NOR"击向$n的裆部",
	"lvl"    : 30,
	"skill_name" : "掏虚式" ,
]),
([	"action" : "$N双手平提胸前，左手护住面门，一招"HIY"「抱残式」"NOR"右手推向$n的$l",
	"lvl"    : 35,
	"skill_name" : "抱残式" ,
]),
([	"action" : "$N两手胸前环抱，腋下含空，五指如钩，一招"HIC"「守缺式」"NOR"插向$n的顶
门",
	"lvl"    : 40,
	"skill_name" : "守缺式" ,
]),
([	"action" : "$N右腿斜插$n二腿之间，一招"HIB"「抢珠式」"NOR"，上手取目，下手反勾$n的
裆部",
	"lvl"    : 45,
	"skill_name" : "抢珠式" ,
]),
([	"action" : "$N一手虚指$n的剑诀，一招"HIR"「夺剑式」"NOR"，一手劈空抓向$n手中的长剑
",
	"lvl"    : 50,
	"skill_name" : "夺剑式" ,
]),
([	"action" : "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招"HIW"「拿云式」"NOR"使
$n进退两难",
	"lvl"    : 55,
	"skill_name" : "拿云式" ,
]),
([	"action" : "$N前脚着地，一手顶天成爪，一手指地，一招"HIY"「追日式」"NOR"劲气笼罩$n
的全身",
	"lvl"    : 60,
	"skill_name" : "追日式" ,
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo) { return combo=="qianye-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练龙爪功必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学龙爪功。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练龙爪功。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练龙爪功。\n");
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
	int d_e1 = 30;
	int d_e2 = 10;
	int p_e1 = -15;
	int p_e2 = -50;
	int f_e1 = 300;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("longzhua-gong", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point() { return 1; }

int help(object me)
{
	write(HIC"\n龙爪功："NOR"\n");
	write(@HELP

    龙爪功只有三十六招，要旨端在凌厉狠辣，不求变化繁多。为
少林七十二绝技之一。
    可与如来千叶手互备。

	学习要求：
		混元一气功20级
		内力100
HELP
	);
	return 1;
}

