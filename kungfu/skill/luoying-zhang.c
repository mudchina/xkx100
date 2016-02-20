// luoying-zhang.c 落英神剑掌
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N双手平伸，向外掠出，一式"GRN"「春云乍展」"NOR"，指尖轻盈漂动，轻轻反点$n的$l",
	"lvl" : 10,
	"skill_name" : "春云乍展"
]),
([	"action" : "$N右手五指缓缓一收，一式"HIG"「回风拂柳」"NOR"，五指忽然遥遥拂向$n，$n只觉得五股疾风袭向自己五处大穴",
	"lvl" : 0,
	"skill_name" : "回风拂柳"
]),
([	"action" : "$N突然纵身跃入半空，一个轻巧转身，单掌劈落，一式"MAG "「江城飞花」"NOR"，拍向$n的头顶",
	"lvl" : 10,
	"skill_name" : "江城飞花"
]),
([	"action" : "$N突然跃起，双手连环，运掌如剑，势如疾风电闪，一式"HIM "「雨急风狂」"NOR"，攻向$n的全身",
	"lvl" : 10,
	"skill_name" : "雨急风狂"
]),
([	"action" : "$N左手挥起，掌心朝天，伸出右手并拢食指中指，捻个剑决，一式"CYN"「星河在天」"NOR"，直指$n的中盘",
	"lvl" : 20,
	"skill_name" : "星河在天"
]),
([	"action" : "$N突然抽身而退，接着一式"HIW"「流华纷飞」"NOR"，平身飞起，双掌向$n的后脑连拍数掌",
	"lvl" : 30,
	"skill_name" : "流华纷飞"
]),
([	"action" : "$N突然抽身跃起，左掌挟着劲风汹涌拍出，接着右掌自左掌后突地伸出，一式"HIR"「彩云追月」"NOR"抢在左掌前向$n的$l拍去",
	"lvl" : 30,
	"skill_name" : "彩云追月"
]),
([	"action" : "$N使一式"HIC"「天如穹庐」"NOR"，全身突然飞速旋转，双掌忽前忽后，猛地拍向$n的胸口",
	"lvl" : 40,
	"skill_name" : "天如穹庐"
]),
([	"action" : "$N前后一揉，一式"HIB"「朝云横度」"NOR"，化掌如剑，一股凌厉剑气袭向$n的下盘",
	"lvl" : 50,
	"skill_name" : "朝云横度"
]),
([	"action" : "$N使一式"HIW"「白虹经天」"NOR"，双掌舞出无数圈劲气，一环环向$n的$l斫去",
	"lvl" : 70,
	"skill_name" : "白虹经天"
]),
([	"action" : "$N双手食指和中指一和，一式"HIM"「紫气东来」"NOR"，一股强烈的气流涌向$n的全身",
	"lvl" : 60,
	"skill_name" : "紫气东来"
]),
([	"action" : "$N一式"HIC"「落英漫天」"NOR"，双掌在身前疾转，掌花飞舞，铺天盖地直指向$n。$n只见漫天掌花，眼花缭乱。",
	"lvl" : 99,
	"skill_name" : "落英漫天"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; } 
int valid_combine(string combo) { return combo=="xuanfeng-leg"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练落英神剑掌必须空手。\n");
	if ((int)me->query_skill("bibo-shengong", 1) < 15)
		return notify_fail("你的碧波神功火候不够，无法学落英神剑掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练落英神剑掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练落英神剑掌。\n");
	me->receive_damage("qi", 25);
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
	int d_e2 = -15;
	int p_e1 = 5;
	int p_e2 = 35;
	int f_e1 = 180;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luoying-zhang", 1);
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
	return __DIR__"luoying-zhang/" + action;
}


int help(object me)
{
	write(HIC"\n落英神剑掌："NOR"\n");
	write(@HELP

    落英神剑掌脱胎于落英神剑，以掌代剑，威力不逊。
    可与旋风扫叶腿互备。

	学习要求：
		碧波神功15级
		内力100
HELP
	);
	return 1;
}

