// duanyun-fu.c 断云斧
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N蓦地腾空跃起，双手紧握$w，对准$n的头顶，自上而下地砍了下去，\n只在半空中留下一团巨大的黑影",
	"lvl" : 0,
	"skill_name" : "开天辟地"
]),
([	"action" : "$N突然发一声喊，冲前两步，手中$w由下而上反撩$n下三路，$n见到一\n道淡黄色的气影逼向自己，情知不妙，急忙招架",
	"lvl" : 20,
	"skill_name" : "气冲霄汉"
]),
([	"action" : "$N忽然虎吼一声，闪身斜向左前方冲出一步，身体微晃，手中$w在空中\n划出一道淡影，急速横扫$n的右肩，气势迫人",
	"lvl" : 40,
	"skill_name" : "横扫千军"
]),
([	"action" : "$N突然抽身向右滚倒，随即跳起，就在跳起的一瞬间，已单臂握着$w砸\n向$n的左肋，出手既快且狠",
	"lvl" : 60,
	"skill_name" : "以退为进"
]),
([	"action" : "$N双手横举$w，平扫$n前胸，招式未使老就已打住猝然变招，斧尖直撞\n$n的小腹，",
	"lvl" : 80,
	"skill_name" : "金斧撞钟"
]),
([	"action" : "$N不急不缓地转身微蹲，$n见$N露出破绽，急忙抢攻，却突然发现$N的\n身体已转过来，手中$w正迅猛地扫向自己的下盘",
	"lvl" : 100,
	"skill_name" : "回风转云"
]),
([	"action" : "$N身形微动，就在同一时间自上中下左右砍出五斧，$n见五把$w从不同\n的方位砍向自己，一时间竟不知该如何招架",
	"lvl" : 120,
	"skill_name" : "五斧夺命"
]),
([	"action" : "$N前脚猛地往地上一顿，大地也微微一震，接着举起斧头在头顶急转
数\n圈，$w就隐含风云之声平直而沉稳地袭向$n，$n无论向何处闪躲，总看见斧尖离\n自己不到一尺，不由大惊失色",
	"lvl" : 150,
	"skill_name" : "一斧断云"
])
});

int valid_enable(string usage) { return usage=="axe" ||	usage=="parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("你的枯荣禅功火候不够，无法学断云斧。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力太弱，无法练断云斧。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "axe")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练断云斧。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 60;
	int d_e2 = 30;
	int p_e1 = -30;
	int p_e2 = -60;
	int f_e1 = 200;
	int f_e2 = 400;
	int m_e1 = 300;
	int m_e2 = 500;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("duanyun-fu", 1);
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
		"damage_type" : random(2) ? "割伤" : "劈伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me)
{
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"duanyun-fu/" + action;
}

int help(object me)
{
	write(HIC"\n断云斧："NOR"\n");
	write(@HELP

    断云斧为天南大理段家的武功。

	学习要求：
		枯荣禅功20级
		内力150
HELP
	);
	return 1;
}

