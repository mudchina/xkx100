// quanzhen-sword.c 全真剑法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N意带神闲，一式"GRN"「分花拂柳」"NOR"，$w轻轻飞动，幻起一片剑光，围掠$n全身",
	"lvl" : 0,
	"skill_name" : "分花拂柳"
]),
([	"action":"$N使一招"HIY"「琴心三叠」"NOR"，身形向上飘起，手中$w虚虚实实幻出三点寒光射向$n$l",
	"lvl" : 9,
	"skill_name" : "琴心三叠"
]),
([	"action":"$N身形一转，猛然一式"HIG"「罡风扫叶」"NOR"，舞出满天剑影，挟着劲风向$n的$l扫去",
	"lvl" : 18,
	"skill_name" : "罡风扫叶"
]),
([	"action":"$N仰天长笑，身形飘然而起，在半空中身子一旋，一式"HIM"「狂歌痛饮」"NOR"狂风般地击向$n",
	"lvl" : 27,
	"skill_name" : "狂歌痛饮"
]),
([	"action":"$N左手捏着剑诀，右足踏开一招"RED"「定阳针」"NOR"向上斜刺，长剑锵然跃出倏的化作几点星光射向$n的$l",
	"lvl" : 36,
	"skill_name" : "定阳针"
]),
([	"action":"$N向前迈去一大步，使出"HIB"「探海屠龙」"NOR"，手中$w舞成一个光球，迅若奔雷击向$n的$l",
	"lvl" : 45,
	"skill_name" : "探海屠龙"
]),
([	"action":"$N运力一抖$w，一时"HIM"「马蹴落花」"NOR"，$w幻出点点剑花，飘然刺向$n的$l",
	"lvl" : 54,
	"skill_name" : "马蹴落花"
]),
([	"action":"$N手中$w斜指苍天，纵起丈余，一时"YEL"「横行漠北」"NOR"，$w雷霆般射向$n的$l",
	"lvl" : 63,
	"skill_name" : "横行漠北"
]),
([	"action":"$N大喝一声，一招"HIW"「白虹经天」"NOR"，$w闪电般划出一道大圆弧劈向$n的$l",
	"lvl" : 72,
	"skill_name" : "白虹经天"
]),
([	"action":"$N身形向上飘起，突然一转身，头下脚上，手握$w，一招"HIW"「絮坠无声」"NOR"，无声无息地攻向$n的$l",
	"lvl" : 81,
	"skill_name" : "絮坠无声"
]),
([	"action":"$N手中$w一抖，一招"HIR"「照破万缘」"NOR"，$w逼出耀眼光芒，奋力击向$n的$l",
	"lvl" : 90,
	"skill_name" : "照破万缘"
]),
([	"action":"$N忽然身形高高跃起，使出"HIC"「浪迹天涯」"NOR"，$w幻出漫天花瓣，迅如雷霆射向$n的$l",
	"lvl" : 150,
	"skill_name" : "浪迹天涯"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("yunv-xinfa", 1) < 25 &&
		(int)me->query_skill("xiantian-qigong", 1) < 25)
		return notify_fail("你的内功心法火候不到，无法学习全真剑法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 55)
		return notify_fail("你的体力不够练全真剑法。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不足以练全真剑法。\n");
	me->receive_damage("qi", 50);
	me->add("neili", -35);
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
	int d_e1 = -20;
	int d_e2 = 0;
	int p_e1 = -50;
	int p_e2 = -30;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 190;
	int m_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("quanzhen-jian", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) 
{ 
  if(me->query_skill("xiantian-qigong",1) > 10) return 1.0;
  else return 0.6;
}

string perform_action_file(string action)
{
	return __DIR__"quanzhen-jian/" + action;
}
int help(object me)
{
	write(HIC"\n全真剑法："NOR"\n");
	write(@HELP

    全真剑法以法度严谨、招式狠辣著称，创派祖师王重阳少年时
仗此剑法诛杀奸邪，鞑子闻风丧胆。

	学习要求：
		先天气功或玉女心法25级
		内力100
HELP
	);
	return 1;
}

