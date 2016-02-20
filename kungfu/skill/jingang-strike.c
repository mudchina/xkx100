// Last Modified by Winder on May. 29 2001
// jingang-strike.c 大金刚神掌 和多罗叶指互备 取自《天龙八部》等。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
 
mapping *action = ({
([	"action" : "$N蔼然微笑，一式"HIY"「礼敬如来」"NOR"，双手合十向前微微一拜，一股暗劲蓄势而发，击向$n的$l",
	 "lvl"   : 0,
	 "skill_name" : "礼敬如来"
]),
([	"action" : "$N面色恭敬，一式"HIY"「遇佛传法」"NOR"，闪到$n的身后，左手单拳在胸前一立，右手成掌直击$n的后脑",
	 "lvl"   : 10,
	 "skill_name" : "遇佛传法"
]),
([	"action" : "$N一声冷笑，一式"HIY"「幽冥搜魂」"NOR"双拳快速交替击出十数掌，掌带风声呼呼作响，令$n不住倒退，疲于招架",
	 "lvl"   : 20,
	 "skill_name" : "幽冥搜魂"
]),
([	"action" : "$N暴雷般大喝声中，一式"HIY"「引火炼妖」"NOR"，双掌相搓，一前一后，挟着一股热浪推向$n",
	 "lvl"   : 30,
	 "skill_name" : "引火炼妖"
]),
([	"action" : "$N一式"HIY"「魂散心魔」"NOR"，低眉垂目之间，突然双掌直上直下，不成章法，犹如疯魔一般攻向$n的身前身后",
	 "lvl"   : 40,
	 "skill_name" : "魂散心魔"
]),
([	"action" : "$N一式"HIY"「无相法相」"NOR"，右掌虚晃，身形一变，已化出数十个幻影，齐齐印向$n的全身各处要穴",
	 "lvl"   : 60,
	 "skill_name" : "无相法相"
]),
([	"action" : "$N腾身跃起，半空中出现巨大身影，突然一式"HIY"「攀天祥云」"NOR"，头下脚上，旋转着俯冲下来，双掌兜住$n",
	 "lvl"   : 80,
	 "skill_name" : "攀天祥云"
]),
([	"action" : "$N庄严伫立，深深吸了一口气，全身衣服微微涨起，低喝一声，一式"HIY"「超度极乐」"NOR"，内力澎湃而出，击向$n的前胸",
	 "lvl"   : 100,
	 "skill_name" : "超度极乐"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo){ return combo=="duoluoye-finger"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练大金刚神掌必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 50)
		return notify_fail("你的站桩功火候不够，无法学大金刚神掌。\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法练大金刚神掌。\n");
	if ((me->query_skill("boluomi-hand", 1) < 50) ||
		(me->query_skill("sanhua-strike", 1) < 50))
		return notify_fail("你的波罗蜜手和散花掌火候不够，无法学大金刚神掌。\n");
	return 1;
}
int practice_skill(object me)
{
	 if ((int)me->query("qi") < 50)
		 return notify_fail("你的体力太低了。\n");
	 if ((int)me->query("neili") < 20)
		 return notify_fail("你的内力不够练大金刚神掌。\n");
	 me->receive_damage("qi", 45);
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
	int d_e2 = -25;
	int p_e1 = -5;
	int p_e2 = 20;
	int f_e1 = 210;
	int f_e2 = 320;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jingang-strike", 1);
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
	 return __DIR__"jingang-strike/" + action;
}

int help(object me)
{
	write(HIC"\n大金刚神掌："NOR"\n");
	write(@HELP

    大金刚神掌是南少林掌法，和多罗叶指互备。

	学习要求：
		站桩功50级
		散花掌50级
		如来千叶手50级
		内力修为500
HELP
	);
	return 1;
}

