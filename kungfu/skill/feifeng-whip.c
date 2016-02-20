// feifeng-whip.c 飞凤鞭法
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N向上跃起，一招"MAG"「凤凰展翅」"NOR"，手中$w自下而上，击向$n的脸颊",
	"lvl"    : 0,
	"skill_name" : "凤凰展翅",
]),
([	"action" : "$N一招"MAG"「彩凤栖梧」"NOR"，手中$w直绕向$n的$l",
	"lvl"    : 20,
	"skill_name" : "彩凤栖梧",
]),
([	"action" : "$N一招"HIY"「鸾凤和鸣」"NOR"，手中$w腾空一卷，一声脆响入磬，猛地向$n劈头打下",
	"lvl"    : 40,
	"skill_name" : "鸾凤和鸣",
]),
([	"action" : "$N踏上一步，冲着$n轻佻一笑，手中$w却毫不停留，一招"HIG "「游龙戏凤」"NOR"，扫向$n的$l",
	"lvl"    : 50,
	"skill_name" : "游龙戏凤",
]),
([	"action" : "$N跃在半空，一招"HIR"「龙飞凤舞」"NOR"，手中$w如游龙洗空，长凤戏羽，乱雨倾盆般分点$n左右",
	"lvl"    : 60,
	"skill_name" : "龙飞凤舞",
]),
([	"action" : "$N向前急进，手中$w圈转如虹，一招"HIM"「龙凤呈祥」"NOR"，罩向$n前胸",
	"lvl"    : 75,
	"skill_name" : "龙凤呈祥",
])
});

int valid_enable(string usage) { return (usage=="whip") || (usage=="parry"); }

int valid_learn(object me)
{
	object weapon;

	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("你的枯荣禅功火候太浅。\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力不够。\n");
	if ( me->query("gender") != "女性")
		return notify_fail("大老爷们学这飞凤鞭？天资不足吧。\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条长鞭才能练鞭法。\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 5 || (int)me->query("neili") < 5 )
		return notify_fail("你的体力不够练飞凤鞭法。\n");
	me->receive_damage("qi", 5);
	me->add("neili", -5);
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
	int d_e1 = -40;
	int d_e2 = -35;
	int p_e1 = 5;
	int p_e2 = 20;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 100;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("feifeng-whip", 1);
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
		"damage_type" : random(2) ? "瘀伤": "刺伤",
	]);
}

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point() { return 1.0; }

int help(object me)
{
	write(HIC"\n飞凤鞭法："NOR"\n");
	write(@HELP

    飞凤鞭法为天南大理段家的武功。大理镇南王段正淳妻子刀白
凤成名绝技，唯女子能学。

	学习要求：
		女性
		枯荣禅功20级
		内力100
HELP
	);
	return 1;
}

