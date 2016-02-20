// yuxiao-jian.c 玉箫剑法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$N漫步提腰，一招"+(order[random(13)])+"「英雄潇洒我独行」"NOR"，飘然来至$n面前，随即手中$w微震，剑尖疾点向$n的$l",
	"lvl" : 0,
	"skill_name": "英雄潇洒我独行"
]),
([	"action" : "$N斜跨一步，使出一式"+(order[random(13)])+"「儿女情长只恨短」"NOR"，挥剑舞出两道一长一短的光影直刺$n的$l",
	"lvl" : 10,
	"skill_name" : "儿女情长只恨短"
]),
([	"action" : "$N一招"+(order[random(13)])+"「翩然离去不思归」"NOR"，$w骤然出鞘又立刻回到剑鞘中，随即转身翩然离去。$n这时才感觉到有一股劲气逼向自己的$l",
	"lvl" : 20,
	"skill_name": "翩然离去不思归"
]),
([	"action" : "$N双手举剑向天，一招"+(order[random(13)])+"「傲立群雄无所惧」"NOR"，$w带起阵阵惊雷，自上而下向$n的头颅剁去",
	"lvl" : 30,
	"skill_name": "傲立群雄无所惧"
]),
([	"action" : "$N施展出"+(order[random(13)])+"「倾城一笑万人醉」"NOR"，手握$w颔首微微一笑，$n只看得一呆，却见一道剑影犹如龙游般袭向自己的$l，而自己却没看清$N何时出的手",
	"lvl" : 40,
	"skill_name" : "倾城一笑万人醉"
]),
([	"action" : "$N左脚踏实，右脚虚点，一招"+(order[random(13)])+"「一曲奏毕愁肠结」"NOR"，$w带着一团剑花，飘浮不定地逼向$n的$l",
	"lvl" : 50,
	"skill_name": "一曲奏毕愁肠结"
]),
([	"action" : "$N一招"+(order[random(13)])+"「处子弄箫亦多情」"NOR"，左手轻抚$w，随即猛地一弹，右手向前一递，只见一道闪烁不定的剑影迅速刺向$n的$l",
	"lvl" : 60,
	"skill_name" : "处子弄箫亦多情"
]),
([	"action" : "$N回身低首，神色黯然，一招"+(order[random(13)])+"「闻声哀怨断人肠」"NOR"，$w剑尖游移不定地刺向$n的$l",
	"lvl" : 70,
	"skill_name" : "闻声哀怨断人肠"
]),
([	"action" : "$N坐手掩面，一招"+(order[random(13)])+"「彼将离兮泪涟涟」"NOR"，右手$w斜向下划出，$n微觉奇怪，正迟疑间，却见$N手中的$w已反挑而上，直刺自己的咽喉",
	"lvl" : 80,
	"skill_name": "彼将离兮泪涟涟"
]),
([	"action" : "$N忽然面露微笑，一招"+(order[random(13)])+"「随音而舞笑开颜」"NOR"，右手$w一闪，舞出三团剑花刺向$n的上中下三路",
	"lvl" : 90,
	"skill_name" : "随音而舞笑开颜"
]),
([	"action" : "$N左手食指疾点$w，一招"+(order[random(13)])+"「箫音有情人无情」"NOR"，$w发出一声龙吟，余音缭绕，$n只觉得胸前一闷，一阵刚猛的劲气迫向自己",
	"lvl" : 100,
	"skill_name" : "箫音有情人无情"
]),
([	"action" : "$N右手微震，一招"+(order[random(13)])+"「箫声响毕情两断」"NOR"，手中$w急颤，发出一阵震耳欲聋的轰鸣，刹那间飞沙走石，$n已在一团剑光的笼罩下，正勉力支撑着",
	"lvl" : 110,
	"skill_name" : "箫声响毕情两断"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if (((int)me->query("max_neili") < 500) ||
		((int)me->query_skill("bibo-shengong", 1) < 100) ||
		!(me->query("couple/have_couple")))
		return notify_fail("黄药师说道: 玉箫剑法，只付有缘。你不是性情中人。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 55)
		return notify_fail("你的体力不够练玉箫剑法。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不足以练玉箫剑法。\n");
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
	int m_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yuxiao-jian", 1);
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
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"yuxiao-jian/" + action;
}
int help(object me)
{
	write(HIC"\n玉箫剑法："NOR"\n");
	write(@HELP

    玉箫剑法是东海桃花岛主黄药师的不传之密。
    在桃花岛竹林内“积翠亭”两旁，悬着一副对联：“桃花影里
飞神剑，碧海潮生按玉箫”，隐然黄药师生平两大得意武功。落英
神剑之外就是玉箫剑法了。

	学习要求：
		碧波神功100级
		内力500
		机缘
HELP
	);
	return 1;
}

