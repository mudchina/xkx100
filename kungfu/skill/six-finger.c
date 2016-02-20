// six-fingers.c 六脉神剑
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "少商剑",
	"action": "$N反过手来，双手拇指同时捺出，嗤嗤两声急响，“少商剑”
有如石破天惊、风雨大至之势，分指$n膻中和$l",
	"lvl"   : 0
]),
([	"skill_name" : "商阳剑",
	"action": "$N食指连动，手腕园转，“商阳剑”一剑又一剑的刺出，轻灵
迅速，奇巧活泼，剑气纵横，$n根本无法看清来路",
	"lvl"   : 10
]),
([	"skill_name" : "中冲剑",
	"action": "$N右手中指一竖，“中冲剑”向前刺出。真气鼓荡，嗤然声响，
无形剑气直指$n的$l",
	"lvl"   : 20
]),
([	"skill_name" : "关冲剑",
	"action": "$N右手无名指伸出，“关冲剑”剑路拙滞古朴，一股雄浑的内
力鼓荡而出，如排山倒海般向$n涌去",
	"lvl"   : 30
]),
([	"skill_name" : "少泽剑",
	"action": "$N左手小指一伸，一条气流从少冲穴中激射而出，“少泽剑”
出手入风，指向$n的$l",
	"lvl"   : 40
]),
([	"skill_name" : "少冲剑",
	"action": "$N右手反指，小指伸出，真气自少冲穴激荡而出，“少泽剑”
横生奇变，从$n意想不到的方向刺向$n的$l",
	"lvl"   : 50
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练六脉神剑必须空手。\n");
	if ((int)me->query("max_neili") < 1200)
		return notify_fail("你的内力太弱，无法学六脉神剑。\n");
	if ((int)me->query_skill("kurong-changong",1) < 120)
		return notify_fail("你的枯荣禅功太低，无法学六脉神剑。\n");
	return 1;
}
int practice_skill(object me)
{
	object* ob, obj;
	int i,skill,damage,cost;
	cost=40;
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 160)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练六脉神剑。\n");
	if( skill > 100 && me->query("shen") < 1)
		return notify_fail("这种武功当得行侠义事。\n");
	if ((int)me->query_skill("six-finger", 1)>150) cost=80;
	if ((int)me->query_skill("six-finger", 1)>250) cost=160;
	me->receive_damage("qi", cost);
	me->add("neili", -30);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() )
	{
		victim->receive_wound("qi", (damage_bonus - 100) / 3 );
		return HIR "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;
	}
}
mapping query_action(object me, object weapon)
{
	int d_e1 = 25;
	int d_e2 = 5;
	int p_e1 = -30;
	int p_e2 = -50;
	int f_e1 = 500;
	int f_e2 = 600;
	int i, lvl, seq, ttl = sizeof(action);

	if (random(me->query_skill("six-finger",1)) > 60 &&
		me->query_skill("kurong-changong",1) > 60 &&
		me->query("neili") > 100)
	{
		me->add("neili",-50);
		return ([
			"action" : "$N忽然觉得剑谱中的六路剑法一一涌向心头，十指纷弹，此去彼来，连绵无尽。剑气纵横，尘烟四起，六路剑法回转运使，$n顿时心神大乱，但觉全身几处刺痛，几股鲜血从身上标出。忍痛抬头一看，一柱剑气迎面又到",
			"dodge": 5,
			"parry": -50,
			"force": 600,
			"damage_type": "刺伤"]);
	}
	else
	{
		lvl = (int)me->query_skill("six-finger", 1);
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
			"damage_type" : random(2) ? "内伤" : "刺伤",
		]);
	}
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"six-finger/" + action;
}
int help(object me)
{
	write(HIC"\n六脉神剑："NOR"\n");
	write(@HELP

    六脉神剑是大理段氏不传之秘。天龙寺为大理武学之根本，此
技即为天龙镇寺之宝，俗家弟子无法窥其堂奥。六脉神剑并非普通
剑法，而是以无上内力运指作剑，伤敌于无形，亦即“气剑”。

	学习要求：
		枯荣禅功120级
		内力1200
HELP
	);
	return 1;
}


