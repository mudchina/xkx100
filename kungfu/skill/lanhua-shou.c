// lanhua-shou.c -兰花拂穴手
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N右手五指分开，微微一拨，再并拢向外一拂，一式" MAG"「花疏云淡」"NOR"，拂向$n的膻中要穴",
	"lvl" : 0,
	"skill_name" : "花疏云淡"
]),
([	"action" : "$N侧身掠向$n，一式"CYN"「轻云蔽月」"NOR"，左手五指暗暗运气拨向$n的胸前大穴",
	"lvl" : 10,
	"skill_name" : "轻云蔽月"
]),
([	"action" : "$N使一式"HIW"「云破月来」"NOR"，左掌虚攻，右手并指斜前翻出，拍向$n的肩井穴",
	"lvl" : 20,
	"skill_name" : "云破月来"
]),
([	"action" : "$N左掌护胸，微微侧身，右掌勾上，一式"BLU"「幽兰弄影」"NOR"，缓缓拂向$n的天突穴",
	"lvl" : 30,
	"skill_name" : "幽兰弄影"
]),
([	"action" : "$N使一式"GRN"「芳兰竟体」"NOR"，身影不定地掠至$n身后，猛地拍向$n的大椎穴",
	"lvl" : 42,
	"skill_name" : "芳兰竟体"
]),
([	"action" : "$N两臂左手下右手上地于胸前成兰花指形翻上，微吸一口气，一式"HIG"「兰桂齐芳」"NOR"，双手向外快速一拨，激出数道劲气逼向$n的华盖、璇玑、紫宫几处大穴",
	"lvl" : 54,
	"skill_name" : "兰桂齐芳"
]),
([	"action" : "$N衣袂飘飘，向上跃起，一式"RED"「月影花香」"NOR"，居高临下，拂出一道劲力罩向$n的百会大穴",
	"lvl" : 66,
	"skill_name" : "月影花香"
]),
([	"action" : "$N凝神施展出"HIR"「花好月圆」"NOR"，双手疾拂，一环环的劲气逼向$n的上中下各大要穴",
	"lvl" : 80,
	"skill_name" : "花好月圆"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="tanzhi-shentong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(HIC"练兰花拂穴手必须空手。\n"NOR);
	if ((int)me->query_skill("bibo-shengong", 1) < 20)
		return notify_fail("你的碧波神功火候不够，无法学兰花拂穴手。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练兰花拂穴手。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了，无法练兰花拂穴手。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练兰花拂穴手。\n");
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
	int d_e2 = -20;
	int p_e1 = 10;
	int p_e2 = 40;
	int f_e1 = 170;
	int f_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lanhua-shou", 1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"lanhua-shou/" + action;
}

int help(object me)
{
	write(HIC"\n兰花拂穴手："NOR"\n");
	write(@HELP

    兰花拂穴手是东海桃花岛武功。出手五指状如兰花。
    可与弹指神通互备。

	学习要求：
		碧波神功20级
		内力200
HELP
	);
	return 1;
}

