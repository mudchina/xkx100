// luohua-jian.c 落花十三剑
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N凌空飞起，挽了一个剑花，一招"GRN"「水面风回聚落花」"NOR"，剑光四射就如同千万点寒星，向$n当头洒下",
	"lvl"    : 0,
	"skill_name"  : "水面风回聚落花"
]),
([	"action" : "$N蓦的向前一纵身，左手单掌护胸，右手手腕一沉，$w向上反撩，一式"HIY"「闲敲棋子落灯花」"NOR"划向$n的$l",
	"lvl"    : 20,
	"skill_name"  : "闲敲棋子落灯花"
]),
([	"action" : "$N口中轻叱一声，手中$w向下一点，身形向上拔起丈余，一招"BLU"「骏马行桥踏落花」"NOR"$w居高临下如闪电般刺向$n的$l",
	"lvl"    : 30,
	"skill_name"  : "骏马行桥踏落花"
]),
([	"action" : "$N双脚不丁不八，身形稳如泰山，左手微屈捏成剑决，右手$w轻颤，一式"MAG"「江城五月落梅花」"NOR"，只见满天银光纷纷点点罩向$n的$l",
	"lvl"    : 70,
	"skill_name"  : "江城五月落梅花"
]),
([	"action" : "$N长吸一口真气，一招"RED"「银烛光摇半夜花」"NOR"，右手$w摇曳不定，似有似无地刺向$n",
	"lvl"    : 80,
	"skill_name"  : "银烛光摇半夜花"
]),
([	"action" : "$N双目直视$n，左手疾伸，与右手同时握住$w，剑随意动，一招"HIC"「犹为离人照落花」"NOR"，$w大开大阖，向$n的$l直劈过去",
	"lvl"    : 90,
	"skill_name"  : "犹为离人照落花"
]),
([	"action" : "只见$N左穿右插，剑光闪烁不定，一招"HIM"「更持红烛赏残花」"NOR"，$w极快地划出一个光圈，“呜..呜..”作响，奔向$n的$l",
	"lvl"    : 100,
	"skill_name"  : "更持红烛赏残花"
]),
([	"action" : "$N身形稍挫，一招"HIG"「春城无处不飞花」"NOR"反手击出，只听“嗤”的一声，一道青光射向$n的$l",
	"lvl"    : 110,
	"skill_name"  : "春城无处不飞花"
]),
([	"action" : "$N一声清叱，剑光暴长，一招"HIW"「光摇银海眩生花」"NOR"，攻势突发，手中$w有如长江大河，滚滚而上，涌向$n的$l",
	"lvl"    : 130,
	"skill_name"  : "光摇银海眩生花"
]),
([	"action" : "$N一声长啸，右臂一振，一招"HIR"「长日临池看落花」"NOR"，手中$w作龙吟之声脱手而出，$n只觉一道凌厉的剑气扑面而来",
	"lvl"    : 150,
	"skill_name"  : "长日临池看落花"
]),
([	"action" : "$N身躯一转，一招"HIW"「月明残雪映梅花」"NOR"，内力急吐，$w上突地涨出尺余长的剑芒呼呼作响,划向$n的$l",
	"lvl"    : 160,
	"skill_name"  : "月明残雪映梅花"
]), 
([      "action" : "$N双眉一扬，眼中杀气大盛，一招"HIM"「化作春泥更护花」"NOR"，左脚脚尖点地，右脚迅速向前踏出一步，只见$N与手中$w合而为一，直奔$n而去",     
	"lvl"    : 170,
	"skill_name"  : "化作春泥更护花"
]),
([	"action" : "$N抱元守一，运力于臂，一招"HIR"「人间处处有红花」"NOR"，只见剑光闪闪，四下里剑气纵横，$n几乎要透不过气来",
	"lvl"    : 180,
	"skill_name"  : "人间处处有红花"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 20)
		return notify_fail("你的红花神功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 35 )
		return notify_fail("你的内力或气不够练落花十三剑。\n");
	me->receive_damage("qi", 45);
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
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -5;
	int d_e2 = 15;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 140;
	int m_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luohua-jian", 1);
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
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"luohua-jian/" + action;
}
int help(object me)
{
	write(HIM"\n落花十三剑："NOR"\n");
	write(@HELP

    落花十三剑又称红花十三剑，是红花会本门剑法。

	学习要求：
		红花神功20级
		内力修为100
HELP
	);
	return 1;
}
