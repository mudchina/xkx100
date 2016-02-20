// Last Modified by winder on May. 29 2001
// wuchang-staff.c 无常杖法

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N微一躬身，一招"GRN"「庸人自扰」"NOR"，$w"NOR"带着刺耳的吱吱声，擦地扫向$n的脚踝",
	"lvl" : 0,
	"skill_name" : "庸人自扰"
]),
([	"action": "$N一招"CYN"「想入非非」"NOR"，右手托住杖端，左掌居中一击，令其凭惯性倒向$n的肩头",
	"lvl" : 7,
	"skill_name" : "想入非非"
]),
([	"action": "$N一招"RED"「六神不安」"NOR"，举起$w"NOR"乒乒乓乓地满地乱敲，让$n左闪右避，狼狈不堪",
	"lvl" : 14,
	"skill_name" : "六神不安"
]),
([	"action": "$N一招"MAG"「面无人色」"NOR"，举起$w"NOR"，呆呆地盯了一会，突然猛地一杖打向$n的$l",
	"lvl" : 20,
	"skill_name" : "面无人色"
]),
([	"action": "$N将$w"NOR"顶住自己的胸膛，一端指向$n，一招"YEL"「心惊肉跳」"NOR"，大声叫喊着冲向$n",
	"lvl" : 25,
	"skill_name" : "心惊肉跳"
]),
([	"action": "$N一招"BLU"「行尸走肉」"NOR"，全身僵直，蹦跳着持杖前行，冷不防举杖拦腰向$n劈去",
	"lvl" : 30,
	"skill_name" : "行尸走肉"
]),
([	"action": "$N面带戚色，一招"GRN"「饮恨吞声」"NOR"，趁$n说话间，一杖向$n张大的嘴巴捅了过去",
	"lvl" : 35,
	"skill_name" : "饮恨吞声"
]),
([	"action": "$N一招"YEL"「力不从心」"NOR"，假意将$w"NOR"摔落地上，待$n行来，一脚勾起，击向$n的$l",
	"lvl" : 40,
	"skill_name" : "力不从心"
]),
([	"action": "$N伏地装死，一招"MAG"「穷途没路」"NOR"，一个翻滚，身下$w"NOR"往横里打出，挥向$n的裆部",
	"lvl" : 45,
	"skill_name" : "穷途没路"
]),
([	"action": "$N一招"BLU"「呆若木鸡」"NOR"，身不动，脚不移，$w"NOR"却直飞半空，不偏不倚地砸向$n的$l",
	"lvl" : 50,
	"skill_name" : "呆若木鸡"
]),
([	"action": "$N高举$w，一招"HIB"「人鬼殊途」"NOR"，身形如鬼魅般飘出，对准$n的天灵盖一杖打下",
	"lvl" : 55,
	"skill_name" : "人鬼殊途"
]),
([	"action": "$N一招"HIR"「我入地狱」"NOR"，单腿独立，$w"NOR"舞成千百根相似，根根砸向$n全身各处要害",
	"lvl" : 60,
	"skill_name" : "我入地狱"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 50)
		return notify_fail("你的站桩功火候太浅。\n");
	if ((int)me->query_skill("pudu-staff", 1) < 20)
		return notify_fail("你的普渡杖法火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够练无常杖法。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -15);
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
	int d_e1 = -35;
	int d_e2 = -5;
	int p_e1 = 20;
	int p_e2 = 55;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 160;
	int m_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuchang-staff", 1);
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
		"damage_type" : "挫伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n无常杖法："NOR"\n");
	write(@HELP

    无常杖法是南少林高级杖法。

	学习要求：
		站桩功50级
		普渡杖法20级
		内力修为500
HELP
	);
	return 1;
}

