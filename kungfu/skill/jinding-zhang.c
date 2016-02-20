// jinding-zhang.c 金顶绵掌
// Oct. 9 1997 by That

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "三阳开泰" ,
	"action" : "$N身形微晃，一招"RED"「三阳开泰」"NOR"，掌起风生，$n只觉得一股暖气袭向$l",
	"lvl"   : 0
]),
([	"skill_name" : "五气呈祥" ,
	"action" : "$N双手变幻，五指轻弹，一招"HIR"「五气呈祥」"NOR"，力分五路，招罩十方，抓向$n的$l",
	"lvl"   : 11
]),
([	"skill_name" : "罡风推云" ,
	"action" : "$N左手前引，右手倏出，抢在头里，一招"CYN"「罡风推云」"NOR"，疾抓向$n的$l",
	"lvl"   : 22
]),
([	"skill_name" : "逆流捧沙" ,
	"action" : "$N左手圈转，轻拂$n的左手，反向推出，右手连续磕击，一招"BLU"「逆流捧沙」"NOR"，猛地击向$n的下巴",
	"lvl"   : 33
]),
([	"skill_name" : "雷洞霹雳" ,
	"action" : "$N舌绽春雷，一声娇喝，在$n一愣间，右手一招"HIB"「雷洞霹雳」"NOR"，直捣$n的$l",
	"lvl"   : 44
]),
([	"skill_name" : "金顶佛光" ,
	"action" : "$N双手平举握拳，脸露微笑，$n恍惚间看到$N分身为二，便见$N四掌齐出，一招"HIY"「金顶佛光」"NOR"不知哪两掌是实？掌风已经袭面",
	"lvl"   : 55
]),
([	"skill_name" : "梵心降魔" ,
	"action" : "$N一幅宝像庄严，使出"YEL"「梵心降魔」"NOR"，掌势如虹，绕着$n漂移不定",
	"lvl"   : 66
]),
([	"skill_name" : "法尊八荒" ,
	"action" : "$N全场游走，双臂疾舞，化为点点掌影，一招"HIC"「法尊八荒」"NOR"铺天盖地袭向$n全身各处大穴",
	"lvl"   : 77
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="tiangang-zhi"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练金顶绵掌必须空手。\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 10)
		return notify_fail("你的临济庄心法火候不够，不能练金顶绵掌。\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("你的内力太弱，无法练金顶绵掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 45)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练金顶绵掌。\n");
	me->receive_damage("qi", 40);
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
	int d_e1 = -40;
	int d_e2 = -15;
	int p_e1 = 5;
	int p_e2 = 30;
	int f_e1 = 180;
	int f_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jinding-zhang", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"jinding-zhang/"+ action;
}
int help(object me)
{
	write(HIC"\n金顶绵掌："NOR"\n");
	write(@HELP

    金顶绵掌为峨嵋派掌法。
    可与天罡指穴法互备。

	学习要求：
		临济十二庄20级
		内力30
HELP
	);
	return 1;
}

