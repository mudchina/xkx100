// wudang-jian.c 武当剑法
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" :  "飞燕入林",
	"action" : "$N身体左转，左手剑指，两腿屈膝，右前臂内旋，剑尖前端一寸处短促抖腕发力，一招"HIB"「飞燕入林」"NOR"，手中$w轻轻颤动，一剑自上而下扎向$n的$l",
	"lvl" : 0
]),
([	"skill_name" :  "青龙吐水",
	"action" : "$N身形不动，右前臂外旋，剑刃上崩，立马左腿左弓步，一招"HIG"「青龙吐水」"NOR"，手中$w向前下反刺，一剑指向$n的$l",
	"lvl" : 10
]),
([	"skill_name" :   "凤凰挚窝",
	"action" : "$N左脚向前一步，蹬地跳起，身体腾空疾速左转，右手$w先向前刺，随转体变向，使出一式"MAG"「凤凰挚窝」"NOR"，剑光如匹练般泄向$n的$l",
	"lvl" : 20
]),
([	"skill_name" :   "白蛇吐信",
	"action" : "$N碎步急进，提剑沿剑身方向疾速上崩，一招"HIW"「白蛇吐信」"NOR"直取$n的$l",
	"lvl" : 30
]),
([	"skill_name" :   "玉女穿梭",
	"action" : "$N平剑斜洗，臂圆剑直，双脚交替弧形迈进，右手$w使出一式"HIC"「玉女穿梭」"NOR"，剑锋往来运转如梭，连绵不绝刺向$n的$l",
	"lvl" : 40
]),
([	"skill_name" :   "仙人指路",
	"action" : "$N屈腕抬臂，剑由前向后上方抽带，挺起中平剑奋勇向前，右手$w使出一式"HIY"「仙人指路」"NOR"刺向$n的$l",
	"lvl" : 50
]),
([	"skill_name" :  "怀中抱月",
	"action" : "$N左撤步，抱剑当胸，挥剑做圆环形，正反搅动，右手$w一式"HIG"「怀中抱月」"NOR"，剑意圆润，刺向$n的$l",
	"lvl" : 60
]),
([	"skill_name" :   "反身朝阳",
	"action" : "$N侧身退步，左手剑指划转，腰部一扭，上体后仰，右手$w一记"HIM"「反身朝阳」"NOR"自下上撩指向$n的$l",
	"lvl" : 70
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 10)
		return notify_fail("你的太极神功火候太浅。\n");
	if ((int)me->query_skill("sword", 1) < 10)
		return notify_fail("你的基本剑法火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 10 )
		return notify_fail("你的内力或气不够练武当剑法。\n");
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
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = 5;
	int p_e2 = 25;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 20;
	int m_e2 = 120;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wudang-jian", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n武当剑法："NOR"\n");
	write(@HELP

    武当剑法为武当派入门剑法。

	学习要求：
		太极神功10级
		基本剑法10级
		内力10
HELP
	);
	return 1;
}

