// riyue-whip.c 日月鞭法
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N端坐不动，一式"HIG"「阿那律刺」"NOR"，手腕力抬，$w滚动飞舞，宛如灵蛇乱颤，前缠后绕，其力沾粘不散",
	"lvl"    : 0,
	"skill_name" : "阿那律刺",
]),
([	"action" : "$N一式"HIM"「目捷连刺」"NOR"，将手$w中抖得笔直，“呲呲”声中向$n疾刺而至，所挟劲风已令$n一阵气窒",
	"lvl"    : 30,
	"skill_name" : "目捷连刺",
]),
([	"action" : "$N内劲到处，将$w抖动转成两个圆圈，一式"HIW"「舍利佛刺」"NOR"，跃起从半空中往$n$l缠下",
	"lvl"    : 60,
	"skill_name" : "舍利佛刺",
]),
([	"action" : "$N劲走螺旋，一式"BLU"「富楼那刺」"NOR"，$w在$n眼前上圈下钩，左旋右转，连变了数种招式，忽然从$n$l处倒卷上来",
	"lvl"    : 90,
	"skill_name" : "富楼那刺",
]),
([	"action" : "$N一声高喝，吸气催力，一式"HIB"「迦旋延刺」"NOR"，$w急速转动，鞭影纵横，直中有圆，圆中有直，似真似幻，绞向$n",
	"lvl"    : 120,
	"skill_name" : "迦旋延刺",
]),
([	"action" : "$N含胸拔背、沉肩坠肘，一式"MAG"「弘忍能刺」"NOR"，力道灵动威猛，虚实分明，劲力从四面八方向$n挤压出去",
	"lvl"    : 150,
	"skill_name" : "弘忍能刺",
]),
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("ranmu-blade",1) > 1 ||
		(int)me->query_skill("weituo-chu",1)>1)
		return notify_fail("你如果有达摩老祖的修为，方可同时学习南少林三绝技。\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力修为不足，没有办法练日月鞭法。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 150)
		return notify_fail("你的站桩功火候太浅。\n");
	if ((int)me->query_skill("yijinjing", 1) < 150)
		return notify_fail("你的易筋经神功火候太浅。\n");
	if((int)me->query_skill("xiangmo-whip",1) < 150)
		return notify_fail("你的降魔鞭火候不足，难以领悟日月鞭法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练日月鞭法。\n");
	if ((int)me->query("neili") < 50 )
		return notify_fail("你的内力不够练日月鞭法。\n");
	me->receive_damage("qi",30);
	me->add("neili",-30);	
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int d_e1 = -60;
	int d_e2 = -45;
	int p_e1 = -30;
	int p_e2 = -5;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 400;
	int m_e2 = 550;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("riyue-whip", 1);
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
		"damage_type" : random(2) ? "瘀伤" : "刺伤",
	]);
}

int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"riyue-whip/" + action;
}
int help(object me)
{
        write(HIC"日月鞭法："NOR"\n");
        write(@HELP

    日月鞭法是南少林顶级鞭法。
    韦陀杵、日月鞭法和燃木刀法并列为南少林三绝技。
    三绝技不能同时修习。

        学习要求：
                易筋经150级
                站桩功150级
                降魔鞭150级
                内力修为1500
HELP
        );
        return 1;
}

