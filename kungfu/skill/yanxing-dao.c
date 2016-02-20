// yanxing-dao.c 雁行刀法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "让字诀",
	"action" : "$N使出"MAG"「让字诀」"NOR"，上身侧过，手中刀斜斜砍出，一道白光劈向$n的$l",
	"lvl"    : 0
]),
([	"skill_name" : "打字诀",
	"action" : "$N使出"BLU"「打字诀」"NOR"，左手护顶，大喝一声，右手刀当头直劈，化作一道白芒直向$n的$l砍落",
	"lvl"    : 10
]),
([	"skill_name" : "顶字诀",
	"action" : "$N使出"HIY"「顶字诀」"NOR"，左手后撤，刀斜上招架，顺势下剁，左手自腋下穿出，托住对方手腕，刀光不停指向$n的$l",
	"lvl"    : 20
]),
([	"skill_name" : "引字诀",
	"action" : "$N使出"HIC"「引字诀」"NOR"，侧身而上，身形突闪，左手带过对方$n兵刃，右手刀猛地弹出，把$n绞在刀光中",
	"lvl"    : 30
]),
([	"skill_name" : "套字诀",
	"action" : "$N使出"HIG"「套字诀」"NOR"，身形向后乍然一闪，左手急速缠住$n左手，手中刀一阵乱披风，刀光罩住$n的$l",
	"lvl"    : 40
]),
([	"skill_name" : "陈字诀",
	"action" : "$N使出"HIM"「陈字诀」"NOR"，身法陡变，轻灵飘忽，捉摸不透，乘$n眼花耳鸣之际，右手刀光反卷向$n的$l",
	"lvl"    : 50
]),
([	"skill_name" : "探字诀",
	"action" : "$N使出"HIR"「探字诀」"NOR"，轻盈地一个急转身，两脚撤步，右手刀尽力向前，直抵$n的$l",
	"lvl"    : 60
]),
([	"skill_name" : "逼字诀",
	"action" : "$N凝神使出"HIB"「逼字诀」"NOR"，身随意转，手随心动，绕着$n疾转，手中刀光漫卷，将$n的全身笼罩在自己布下的刀网中，无从逃脱",
	"lvl"    : 70
]),
([	"skill_name" : "藏字诀",
	"action" : "$N凝神使出"GRN"「藏字诀」"NOR"，侧身藏刀，引诱$n前进了一步，刀光陡现，势如千军万马，奔腾而出",
	"lvl"    : 80
]),
([	"skill_name" : "错字诀",
	"action" : "$N凝神使出"RED"「错字诀」"NOR"，双手交叉，刀光批攉，$n实在看不清刀光来向，退后欲避，只觉一阵寒气直逼过来",
	"lvl"    : 90
]),
});

int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候太浅。\n");
	if ((int)me->query_skill("blade", 1) +100 < (int)me->query_skill("yanxing-dao", 1) )
		return notify_fail("你的基本刀法火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练雁行刀。\n");
	me->receive_damage("qi", 10);
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
	int d_e1 = 35;
	int d_e2 = 15;
	int p_e1 = -15;
	int p_e2 = -35;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 170;
	int m_e2 = 280;
/*	int d_e1 = -50;
	int d_e2 = -35;
	int p_e1 = -25;
	int p_e2 = -0;
	int f_e1 = 200;
	int f_e2 = 250;
	int m_e1 = 200;
	int m_e2 = 300;*/
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("yanxing-dao", 1);
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
		"damage_type" : random(2) ? "割伤" : "擦伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"yanxing-dao/" + action;
}
int help(object me)
{
	write(HIC"\n雁行刀法："NOR"\n");
	write(@HELP

    雁行刀法为峨嵋派刀法。

	学习要求：
		基本刀法等级不能低于雁行刀法等级
		临济十二庄20级
		内力50
HELP
	);
	return 1;
}

