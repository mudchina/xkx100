// Last Modified by winder on May. 29 2001
// luohan-cuff.c 少林罗汉拳 与风云手互备 截自《少林拳法》，取其一至三十式。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action" : "$N一式"+(order[random(13)])+"「抱手起式」"NOR"，身体保持站立的姿势不变，双眼平视前方，双掌前探，双手握拳，抓向$n腰间",
	"lvl"   : 0,
	"skill_name" : "抱手起式"
]),
([	"action" : "$N左脚虚踏，一招"+(order[random(13)])+"「平步栽掌」"NOR"，身体仍然保持站立的姿势不变，左手化掌，向前直封而出",
	"lvl"   : 4,
	"skill_name" : "平步栽掌"
]),
([	"action" : "$N右脚原地跺步，左脚踏前勾出，成七星步坐定，一招"+(order[random(13)])+"「跺脚崩挂」"NOR"，右手向右横拉而出",
	"lvl"   : 8,
	"skill_name" : "跺脚崩挂"
]),
([	"action" : "$N全身向前，一招"+(order[random(13)])+"「进步劈砸」"NOR"，右掌向前直劈而落，左掌同时翻掌硬接，自然击出声音",
	"lvl"   : 12,
	"skill_name" : "进步劈砸"
]),
([	"action" : "$N左掌护住右腕不动，右手原地向外翻手抓采，出"+(order[random(13)])+"「采刁出掌」"NOR"，右手不动，左掌向$n直切而出",
	"lvl"   : 16,
	"skill_name" : "采刁出掌"
]),
([	"action" : "$N右脚拖进，向下蹲成玉环步坐定，右手反拳一式"+(order[random(13)])+"「跟步击砸」"NOR"向前劈落，左掌更翻掌而出",
	"lvl"   : 20,
	"skill_name" : "跟步击砸"
]),
([	"action" : "$N保持玉环步姿势坐定不动，左手扣腕，右掌上翻出"+(order[random(13)])+"「顺势采手」"NOR"，以缠丝手向$n$l采出",
	"lvl"   : 24,
	"skill_name" : "顺势采手"
]),
([	"action" : "$N的缠丝手向下采压，身体原地向上立起"+(order[random(13)])+"「双落蹬子」"NOR"，接着起右腿向$n直蹬而出",
	"lvl"   : 28,
	"skill_name" : "双落蹬子"
]),
([	"action" : "$N将右脚尖回勾，以膝盖向前直顶而出"+(order[random(13)])+"「提膝顶破」"NOR"，顺势右拳收腰，左手封掌前推",
	"lvl"   : 32,
	"skill_name" : "提膝顶破"
]),
([	"action" : "$N一招"+(order[random(13)])+"「移步截砸」"NOR"，身体微仰不动，双掌向左同时以圈封手向前采出，接着左掌前托，右拳顺势向前低劈$n",
	"lvl"   : 36,
	"skill_name" : "移步截砸"
]),
([	"action" : "$N将左脚伸直，成弓箭步站定，一招"+(order[random(13)])+"「迎手托架」"NOR"，右手翻掌上架，左手顺势压掌下封",
	"lvl"   : 40,
	"skill_name" : "迎手托架"
]),
([	"action" : "$N一招"+(order[random(13)])+"「采压冲捶」"NOR"，右脚原地跺步，使身体转正，接着左封掌下压，右掌向前直击$n",
	"lvl"   : 44,
	"skill_name" : "采压冲捶"
]),
([	"action" : "$N接着"+(order[random(13)])+"「转身拦截」"NOR"，顺著身体右转之势，收右拳，撩左掌，双手交叉，向$n横劈而出",
	"lvl"   : 48,
	"skill_name" : "转身拦截"
]),
([	"action" : "$N右脚向右踏出　使身体冲向右方，一招"+(order[random(13)])+"「进步冲捶」"NOR"，收左手扣腰，右手化掌向$n圈封而出",
	"lvl"   : 52,
	"skill_name" : "进步冲捶"
]),
([	"action" : "$N一式"+(order[random(13)])+"「回马拉捶」"NOR"，步法左转，成马步坐定，左手挑回扣住腰际，右掌顺势向$n$l击出",
	"lvl"   : 56,
	"skill_name" : "回马拉捶"
]),
([	"action" : "$N又一招"+(order[random(13)])+"「进步冲捶」"NOR"，右手顺势向前圈采而出，步法随著右转之势，左手化掌向$n直击而出",
	"lvl"   : 60,
	"skill_name" : "进步冲捶"
]),
([	"action" : "$N使出"+(order[random(13)])+"「采刁踢」"NOR"，左手以采刁手由上向前勾落，同时，左腿以勾腿式向$n$l勾踢而出",
	"lvl"   : 64,
	"skill_name" : "采刁踢"
]),
([	"action" : "$N将身体重心移至左脚，使右脚离地蓄劲，一招"+(order[random(13)])+"「套步踢」"NOR"，右腿以勾腿式由上向前勾落",
	"lvl"   : 68,
	"skill_name" : "套步踢"
]),
([	"action" : "$N右脚向右落步，以脚尖轻点地面，一招"+(order[random(13)])+"「跨步反砸」"NOR"，左掌一直护肩不动，右掌向右反崩而出",
	"lvl"   : 72,
	"skill_name" : "跨步反砸"
]),
([	"action" : "$N双腿顺势转正，原地跺步，成弓箭步站定，一招"+(order[random(13)])+"「穿刁斜打」"NOR"，右手化掌，向$n$l横切",
	"lvl"   : 76,
	"skill_name" : "穿刁斜打"
]),
([ 	"action" : "$N步法原地向下成马步坐定，一招"+(order[random(13)])+"「低马击砸」"NOR"，右拳击砸於左膝前方，左掌则翻掌硬推",
	"lvl"   : 80,
	"skill_name" : "低马击砸"
]),
([	"action" : "$N一招"+(order[random(13)])+"「起胳托架」"NOR"，将左脚撑直，成弓箭步站定，右拳顺势翻肘，向$n架出",
	"lvl"   : 84,
	"skill_name" : "起胳托架"
]),
([	"action" : "$N右手化掌，向前直采而出，使出"+(order[random(13)])+"「翻身拦打」"NOR"，右脚原地跺步，使身体转向$n踢出",
	"lvl"   : 88,
	"skill_name" : "翻身拦打"
]),
([	"action" : "$N收左手，右手原地向前架采而出，右脚顺势向$n$l直踢，正是一式"+(order[random(13)])+"「进步架打」"NOR"",
	"lvl"   : 92,
	"skill_name" : "进步架打"
]),
([	"action" : "$N将重心放至右脚，使左脚放虚，一招"+(order[random(13)])+"「回步冲捶」"NOR"，向左原地转回，膝盖顺势抵向$n$l",
	"lvl"   : 96,
	"skill_name" : "回步冲捶"
]),
([	"action" : "$N左掌向前直撑，封住底盘，一式"+(order[random(13)])+"「托按侧蹬」"NOR"，右腿转身以反蹬腿向$n蹬出",
	"lvl"   : 100,
	"skill_name" : "托按侧蹬"
]),
([	"action" : "$N一招"+(order[random(13)])+"「采刁撑腿」"NOR"，左掌护住右腕不动，右手原地向外翻手抓采，接著左脚前踢$n",
	"lvl"   : 104,
	"skill_name" : "采刁撑腿"
]),
([	"action" : "$N左掌原地回圈，向前封出，一招"+(order[random(13)])+"「扭步挟肘」"NOR"，右脚猛然拖进，向$n下盘猛踢三脚",
	"lvl"   : 108,
	"skill_name" : "扭步挟肘"
]),
([	"action" : "$N双手化十字手，交叉於胸前，使出"+(order[random(13)])+"「并步迎抄」"NOR"，双腿一跃，并踢$n$l",
	"lvl"   : 112,
	"skill_name" : "并步迎抄"
]),
([	"action" : "$N跟着又是一招"+(order[random(13)])+"「并步迎抄」"NOR"，十字手顺势向上双抄後，双腿凌空再次踢向$n",
	"lvl"   : 120,
	"skill_name" : "并步迎抄"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="fengyun-hand";}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练少林罗汉拳必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 10)
		return notify_fail("你的站桩功火候不够，无法学少林罗汉拳。\n");
	if ((int)me->query_skill("shaolin-cuff", 1) < 10)
		return notify_fail("你的少林南拳火候不够，无法学少林罗汉拳。\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的内力太弱，无法练少林罗汉拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低，不够练少林罗汉拳。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练少林罗汉拳。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 120;
	int f_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luohan-cuff", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n罗汉拳："NOR"\n");
	write(@HELP

    罗汉拳为少林拳法。与风云手互备。

	学习要求：
		站桩功10级
		少林南拳10级
		内力修为10。
HELP
	);
	return 1;
}

