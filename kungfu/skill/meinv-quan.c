// meinv-quan.c 美女拳
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使一招"RED"「红玉击鼓」 "NOR"，双臂交互快击",
	"lvl" : 0,
	"skill_name" : "红玉击鼓"
]),
([	"action" : "$N突然变为"RED"「红拂夜奔」"NOR"，出其不意的叩关直入，令$n大吃一惊",
	"lvl" : 10,
	"skill_name" : "红拂夜奔"
]),
([	"action" : "$N招式一变成"GRN"「绿珠坠楼」"NOR"，扑地攻敌下盘，委实难测",
	"lvl" : 20,
	"skill_name" : "绿珠坠楼"
]),
([	"action" : "$N双掌连拍数下，接著连绵不断拍出，原来是"HIW"「文姬归汉」"NOR"，共胡笳十八拍",
	"lvl" : 30,
	"skill_name" : "文姬归汉"
]),
([	"action" : "$N使出"RED"「红线盗盒」"NOR"，以空手入白刃之技向$n手中兵刃夺去",
	"lvl" : 40,
	"skill_name" : "红线盗盒"
]),
([	"action" : "$N一式"HIB"「木兰弯弓」"NOR"，左手如抱满月，右手疾挥而过，令$n目瞪口呆",
	"lvl" : 60,
	"skill_name" : "木兰弯弓"
]),
([	"action" : "$N忽然昂首如吟明月，双掌从不可思议的角度攻了过来，原来是一招
"HIC"「班姬赋诗」"NOR"。",
	"lvl" : 70,
	"skill_name" : "班姬赋诗"
]),
([	"action" : "$N使招"HIC"「蛮腰纤纤」"NOR"，腰肢轻摆避开，紧跟着挥掌攻击$n的前胸",
	"lvl" : 80,
	"skill_name" : "蛮腰纤纤"
]),
([	"action" : "$N五指在自己头发上一梳，跟著软软的挥了出去，脸上微微一笑，却
是一招"HIW"「丽华梳装」"NOR"。",
	"lvl" : 90,
	"skill_name" : "丽华梳装"
]),
([	"action" : "$N见$n呆住，伸指戳出，却是一招"HIM"「萍姬针神」"NOR"。",
	"lvl" : 110,
	"skill_name" : "萍姬针神"
]),
([	"action" : "$N突然间蹙起眉头，宛如"MAG"「西子捧心」"NOR"，双掌自自己胸口攻出",
	"lvl" : 130,
	"skill_name" : "西子捧心"
]),
([	"action" : "$N脚下翩若惊鸦、矫若游龙，犹如在水上漂行一般，却是一招"HIW "「洛神微步」"NOR"。",
	"lvl" : 150,
	"skill_name" : "洛神微步"
]),
([	"action" : "$N使招"HIM"「曹令割鼻」"NOR"，挥手在自己脸上斜削一掌，左掌削过，右掌又削，连绵不断",
	"lvl" : 180,
	"skill_name" : "曹令割鼻"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练美女拳必须空手。\n");
	if ((int)me->query_skill("yunv-xinfa", 1) < 10)
		return notify_fail("你的玉女心法火候不够，无法学美女拳。\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("你的内力太弱，无法学习美女拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if( (int)me->query("qi") < 70 || (int)me->query("neili") < 70 )
		return notify_fail("你的体力太差了，不能练习美女拳。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
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
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -35;
	int p_e2 = 15;
	int f_e1 = 200;
	int f_e2 = 300;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("meinv-quan", 1);
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

int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"meinv-quan/" + action;
}
int help(object me)
{
	write(HIC"\n美女拳："NOR"\n");
	write(@HELP

    古墓独门武功，奇妙又花巧，拳法的每一招都是模拟一位古代
美女，将千百年来美女变幻莫测的心情神态尽数融入武术之中，婀
娜妩媚、端丽缥缈尽皆有之，人所难测。
    古墓派自林朝英开派，从来传女不传男。这套「美女拳法」，
使出来时娇媚婀娜，却也均是凌厉狠辣的杀手。


	学习要求：
		玉女心法10级
		内力30
HELP
	);
	return 1;
}

