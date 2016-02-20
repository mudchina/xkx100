// yunlong-jian.c 云龙剑
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"\n$N使一式"GRN"「悠悠顺自然」"NOR"，手中$w嗡嗡微振，幻成一条白光刺向$n的$l",
	"lvl" : 0,
	"skill_name" : "悠悠顺自然"
]),
([	"action":"\n$N错步上前，使出"HIC"「来去若梦行」"NOR"，剑意若有若无，$w淡淡地向$n的$l挥去",
	"lvl" : 8,
	"skill_name" : "来去若梦行"
]),
([	"action":"\n$N一式"HIB"「志当存高远」"NOR"，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
	"lvl" : 15,
	"skill_name" : "志当存高远"
]),
([	"action":"$N纵身轻轻跃起，一式"HIW"「表里俱澄澈」"NOR"，剑光如水，一泻千里，洒向$n全身",
	"lvl" : 20,
	"skill_name" : "表里俱澄澈"
]),
([	"action":"$N手中$w中宫直进，一式"BLU"「随风潜入夜」"NOR"，无声无息地对准$n的$l刺出一剑",
	"lvl" : 30,
	"skill_name" : "随风潜入夜"
]),
([	"action":"$N手中$w一沉，一式"HIG"「润物细无声」"NOR"，无声无息地滑向$n的$l",
	"lvl" : 40,
	"skill_name" : "润物细无声"
]),
([	"action":"\n$N手中$w斜指苍天，剑芒吞吐，一式"HIY"「云龙听梵音」"NOR"，对准$n的$l斜斜击出",
	"lvl" : 50,
	"skill_name" : "云龙听梵音"
]),
([	"action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式"RED"「万里一点红」"NOR"刺向$n的咽喉",
	"lvl" : 60,
	"skill_name" : "万里一点红"
]),
([	"action":"$N合掌跌坐，一式"MAG"「我心化云龙」"NOR"，$w自怀中跃出，如疾电般射向$n的胸口",
	"lvl" : 70,
	"skill_name" : "我心化云龙"
]),
([	"action":"\n$N呼的一声拔地而起，一式"HIY"「日月与同辉」"NOR"，$w幻出万道光影，将$n团团围住",
	"lvl" : 80,
	"skill_name" : "日月与同辉"
]),
([	"action":"$N随风轻轻飘落，一式"GRN"「清风知我意」"NOR"，手中$w平指，缓缓拍向$n脸颊",
	"lvl" : 90,
	"skill_name" : "清风知我意"
]),
([	"action" : "$N剑尖微颤作龙吟，一招"HIW"「高处不胜寒」"NOR"，切骨剑气如飓风般裹向$n全身",
	"lvl" : 100,
	"skill_name" : "高处不胜寒"
]),
([	"action" : "$N募的使一招"HIR"「红叶舞秋山」"NOR"，顿时剑光中几朵血花洒向$n全身",
	"lvl" : 110,
	"skill_name" : "红叶舞秋山"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 20)
		return notify_fail("你的云龙神功火候太浅。\n");
	if ((int)me->query_skill("yunlong-xinfa", 1) < 20)
		return notify_fail("你的云龙心法火候太浅。\n");
	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("你的基本内功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 20)
		return notify_fail("你的云龙神功火候太浅。\n");
	if( (int)me->query("qi") < 55 || (int)me->query("neili") < 40 )
		return notify_fail("你的内力或气不够练云龙剑法。\n");
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
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = -45;
	int p_e2 = -25;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 180;
	int m_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yunlong-jian", 1);
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
int power_point(object me) { 
	if ((int)me->query_skill("yunlong-xinfa",1) < 100)
	return 0.7; 
	else if ((int)me->query_skill("yunlong-xinfa",1) > 200)
	return 1.4;
	else return ( ((int)me->query_skill("yunlong-xinfa",1)-100)/100*0.7+0.7 );
}
string perform_action_file(string action)
{
	return __DIR__"yunlong-jian/" + action;
}
int help(object me)
{
	write(HIC"\n云龙剑法："NOR"\n");
	write(@HELP

    天地会看家本领，其特殊攻击法威力奇大，堪称武林一绝。

	学习要求：
		基本内功40级
		云龙神功20级
		云龙心法20级
		内力200
HELP
	);
	return 1;
}

