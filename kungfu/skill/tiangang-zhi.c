// tiangang-zhi.c 天罡指穴法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N左手轻轻拨动，右手五指徐徐弹出拨，一式"CYN"「浪起湖心」"NOR"，拂向$n的$l",
	"lvl" : 0,
	"skill_name" : "浪起湖心"
]),
([	"action" : "$N双手上下起落，俯身掠向$n，一式"HIC"「瀑落清潭」"NOR"，左手化掌成指，汹涌袭向$n的$l",
	"lvl" : 12,
	"skill_name" : "瀑落清潭"
]),
([	"action" : "$N左手由拳变掌，右手扭曲如灵蛇，一式"BLU"「龟蛇竞渡」"NOR"，左右并用，拍向$n的$l",
	"lvl" : 24,
	"skill_name" : "龟蛇竞渡"
]),
([	"action" : "$N一式"YEL"「倒索攀山」"NOR"，左手抽回，右手前探，戟指点向$n的$l",	
	"lvl" : 36,
	"skill_name" : "倒索攀山"
]),
([	"action" : "$N使一式"MAG"「闪现雷鸣」"NOR"，身影变幻不定地掠至$n身后，猛地拍向$n的$l",
	"lvl" : 48,
	"skill_name" : "闪现雷鸣"
]),
([	"action" : "$N两臂大开大阖，吸一口气，一式"HIB"「地动山摇」"NOR"，劲力透彻，双手快速一拨，激出数道劲气逼向$n的$l",
	"lvl" : 60,
	"skill_name" : "地动山摇"
]),
([	"action" : "$N身形纵起，衣袂飘荡，双手轻轻拍动，一式"HIW"「水拍云崖」"NOR"，居高临下，连绵不绝拍向$n的$l",
	"lvl" : 72,
	"skill_name" : "水拍云崖"
]),
([	"action" : "$N腾空而起，双掌合一，十指如钩，一招"HIY"「泰山压顶」"NOR"，疾向$n的击落，势道凶猛已极",
	"lvl" : 84,
	"skill_name" : "泰山压顶"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jinding-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(HIC"练天罡指穴法必须空手。\n"NOR);
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候不够，无法学天罡指穴法。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练天罡指穴法。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了，无法练天罡指穴法。\n");
	if ((int)me->query("neili") < 25)
		return notify_fail("你的内力不够练天罡指穴法。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -10;
	int f_e1 = 260;
	int f_e2 = 360;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tiangang-zhi", 1);
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
		"damage_type" : random(2) ? "刺伤" : "瘀伤",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tiangang-zhi/" + action;
}
int help(object me)
{
	write(HIC"\n天罡指穴法："NOR"\n");
	write(@HELP

    天罡指穴法为峨嵋派武功。
    可与金顶绵掌互备。

	学习要求：
		临济十二庄20级
		内力100
HELP
	);
	return 1;
}

