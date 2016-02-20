// haotian-zhang 昊天掌
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$N使一招"+(order[random(13)])+"「春江潮水」"NOR"，双手划了个半圈，按向$n的$l",
	"skill_name" : "春江潮水",
	"lvl" : 0
]),
([	"action" : "$N使一招"+(order[random(13)])+"「海上明月」"NOR"，左手轻轻一挥，劈向$n的$l",
	"skill_name" : "海上明月",
	"lvl" : 5
]),
([	"action" : "$N右手掌心向外，由右向左，使一招"+(order[random(13)])+"「滟滟随波」"NOR"，向$n的$l打去",
	"skill_name" : "滟滟随波",
	"lvl" : 10
]),
([	"action" : "$N使一招"+(order[random(13)])+"「江流宛转」"NOR"，分击$n的胸口和$l",
	"skill_name" : "江流宛转",
	"lvl" : 15
]),
([	"action" : "$N使一招"+(order[random(13)])+"「月照花林」"NOR"，左右掌同时击出，在空中突然左右掌方向互
变",
	"skill_name" : "月照花林",
	"lvl" : 20
]),
([	"action" : "$N左手不住晃动，右掌一招"+(order[random(13)])+"「空中流霜」"NOR"，向$n的$l打去",
	"skill_name" : "空中流霜",
	"lvl" : 25
]),
([	"action" : "$N左手变掌为啄，右掌立掌如刀，一招"+(order[random(13)])+"「汀上白沙」"NOR"，劈向$n的$l",
	"skill_name" : "汀上白沙",
	"lvl" : 30
]),
([	"action" : "$N左脚退后半步，右掌使一招"+(order[random(13)])+"「江天一色」"NOR"，横挥向$n",
	"skill_name" : "江天一色",
	"lvl" : 35
]),
([	"action" : "$N一招"+(order[random(13)])+"「皎皎孤月」"NOR"，左掌先发而后至，右掌后发而先至",
	"skill_name" : "皎皎孤月",
	"lvl" : 40
]),
([	"action" : "$N双掌缩入袖中，双袖飞起扫向$n的$l，却是一招"+(order[random(13)])+"「长江流水」"NOR"，仪
态潇洒",
	"skill_name" : "长江流水",
	"lvl" : 45
]),
([	"action" : "$N左手虚按，右手划道弧线使一招"+(order[random(13)])+"「白云悠悠」"NOR"，向$n的$l插去",
	"skill_name" : "白云悠悠",
	"lvl" : 50
]),
([	"action" : "$N双手变掌做拳，向前向后划弧，一招"+(order[random(13)])+"「青枫浦上」"NOR"击向$n的$l",
	"skill_name" : "青枫浦上",
	"lvl" : 55
]),
([	"action" : "$N左手虚划，右手变掌为钩一记"+(order[random(13)])+"「楼月蜚回」"NOR"击向$n的$l",
	"skill_name" : "楼月蜚回",
	"lvl" : 60
]),
([	"action" : "$N施出"+(order[random(13)])+"「玉户帘中」"NOR"，右掌向外挥出，左掌同时攻向$n",
	"skill_name" : "玉户帘中",
	"lvl" : 65
]),
([	"action" : "$N由臂带手，在面前缓缓划过，使一招"+(order[random(13)])+"「鸿雁长飞」"NOR"，挥向$n的$l",
	"skill_name" : "鸿雁长飞",
	"lvl" : 70
]),
([	"action" : "$N负身就地，右掌使一招"+(order[random(13)])+"「鱼龙潜跃」"NOR"，自下而上向$n的$l击去",
	"skill_name" : "鱼龙潜跃",
	"lvl" : 75
]),
([	"action" : "$N右手由钩变掌，双手掌心向上，右掌向前推出一招"+(order[random(13)])+"「月华流照」"NOR"",
	"skill_name" : "月华流照",
	"lvl" : 80
]),
([	"action" : "$N右掌不住向外扫出，是一式"+(order[random(13)])+"「闲潭落花」"NOR"，左掌旋转着向$n攻去",
	"skill_name" : "闲潭落花",
	"lvl" : 85
]),
([	"action" : "$N右手经腹前经左肋向前撇出，使一招"+(order[random(13)])+"「江水流春」"NOR"，向$n的$l锤去
",
	"skill_name" : "江水流春",
	"lvl" : 90
]),
([	"action" : "$N使一招"+(order[random(13)])+"「斜月沉沉」"NOR"，左掌连划三个大圈，右掌从圈中穿出击向$n
",
	"skill_name" : "斜月沉沉",
	"lvl" : 95
]),
([	"action" : "$N左手向上划弧拦出，右手使一招"+(order[random(13)])+"「碣石潇湘」"NOR"，手掌不住晃动，不
离$n头顶方寸之间",
	"skill_name" : "碣石潇湘",
	"lvl" : 100
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="chunyang-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练昊天掌必须空手。\n");
	if ((int)me->query_skill("xiantian-qigong", 1) < 20)
		return notify_fail("你的先天气功火候不够，无法学昊天掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 45)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练昊天掌。\n");
	me->receive_damage("qi", 40);
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
	int d_e1 = -40;
	int d_e2 = -20;
	int p_e1 = 0;
	int p_e2 = 30;
	int f_e1 = 190;
	int f_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("haotian-zhang", 1);
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
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"haotian-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n昊天掌："NOR"\n");
	write(@HELP

    昊天掌为全真派武功。
    可与纯阳拳互备。

	学习要求：
		先天气功20级
HELP
	);
	return 1;
}

