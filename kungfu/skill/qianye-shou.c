// qianye-shou.c 如来千叶手
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIB"「南海礼佛」"NOR"，右手虚晃，左手扬起，突然拍向$n的背后二穴",
	"lvl" : 0,
	"skill_name" : "南海礼佛"
]),
([	"action" : "$N侧身一晃，一式"HIY"「金玉瓦砾」"NOR"，左手拿向$n的肩头，右拳打向$n的胸口",
	"lvl" : 10,
	"skill_name" : "金玉瓦砾"
]),
([	"action" : "$N一式"HIG"「人命呼吸」"NOR"，右手环拢成爪，一出手就向扣$n的咽喉要害",
	"lvl" : 20,
	"skill_name" : "人命呼吸"
]),
([	"action" : "$N左手虚招，右掌直立，一式"HIW"「镜里观影」"NOR"，错步飘出，疾拍$n的面门",
	"lvl" : 30,
	"skill_name" : "镜里观影"
]),
([	"action" : "$N使一式"CYN"「水中捉月」"NOR"，左拳上格，右手探底突出，抓向$n的裆部",
	"lvl" : 38,
	"skill_name" : "水中捉月"
]),
([	"action" : "$N双拳挥舞，一式"HIC"「浮云去来」"NOR"，两手环扣，拢成圈状，猛击$n的下颌",
	"lvl" : 45,
	"skill_name" : "浮云去来"
]),
([	"action" : "$N一式"HIM"「水泡出没」"NOR"，十指伸缩，虚虚实实地袭向$n的全身要穴",
	"lvl" : 51,
	"skill_name" : "水泡出没"
]),
([	"action" : "$N双手抱拳，一式"RED"「梦里明明」"NOR"，掌影翻飞，同时向$n施出九九八十一招",
	"lvl" : 56,
	"skill_name" : "梦里明明"
]),
([	"action" : "$N一式"HIR"「觉后空空」"NOR"，拳招若隐若现，若有若无，缓缓地拍向$n的丹田",
	"lvl" : 60,
	"skill_name" : "觉后空空"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }	
int valid_combine(string combo) { return combo=="longzhua-gong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练如来千叶手必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学如来千叶手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练如来千叶手。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练如来千叶手。\n");
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
	int d_e1 = -50;
	int d_e2 = -15;
	int p_e1 = 15;
	int p_e2 = 40;
	int f_e1 = 160;
	int f_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qianye-shou", 1);
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
	return __DIR__"qianye-shou/" + action;
}

int help(object me)
{
	write(HIC"\n如来千叶手："NOR"\n");
	write(@HELP

    如来千叶手为少林七十二绝技之一。
    可与龙爪功互备。

	学习要求：
		混元一气功20级
		内力100
HELP
	);
	return 1;
}

