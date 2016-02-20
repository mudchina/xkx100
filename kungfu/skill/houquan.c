// houquan.c 猴拳
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "\$N单腿微曲，忽的向前扑出，一式"HIM"「仙猴摘桃」"NOR"，二爪直出，抓向$n的双眼",
	"lvl" : 0,
	"skill_name" : "横空出世"
]),
([	"action" : "$N左手虚晃，一式"GRN"「灵猴攀枝」"NOR"，右手直击，反扣$n的肩井大穴",
	"lvl" : 8,
	"skill_name" : "灵猴攀枝"
]),
([	"action" : "$N一臂前伸，一臂后指，一式"HIW"「猿臂轻舒」"NOR"，攻向$n的两肋",
	"lvl" : 15,
	"skill_name" : "猿臂轻舒"
]),
([	"action" : "\n$N忽然缩成一团，使一式"CYN"「八方幻影」"NOR"，双掌无形无定，一爪抓向$n的胸口",
	"lvl" : 15,
	"skill_name" : "八方幻影"
]),
([	"action" : "$N猛吸一口气，一弯腰，使一式"HIB"「水中揽月」"NOR"，双爪疾扣向$n的小腹",
	"lvl" : 20,
	"skill_name" : "水中揽月"
]),
([	"action" : "$N猛的向上高高跃起，一式"HIY"「落地摘星」"NOR"，居高临下，一爪罩向$n的头骨",
	"lvl" : 30,
	"skill_name" : "落地摘星"
]),
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="cuff";
}
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练猴拳必须空手。\n");
	if ((int)me->query_skill("yunlong-shengong",1) < 10)
	  return notify_fail("你的云龙神功火候不够，无法学猴拳。\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候不够，无法学猴拳。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练猴拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 15)
		return notify_fail("你的内力不够练猴拳。\n");
	me->receive_damage("qi", 20);
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
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 80;
	int f_e2 = 230;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("houquan", 1);
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
		"damage_type" : "瘀伤",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"houquan/" + action;
}
int help(object me)
{
	write(HIC"\n猴拳："NOR"\n");
	write(@HELP

    武林前辈模仿猿猴扑击动作而创出的一套拳法，以轻灵翔动为
其主要特点。 
    猴拳为天地会云龙门武功。

	学习要求：
		云龙神功10级
		基本内功30级
		内力200
HELP
	);
	return 1;
}

