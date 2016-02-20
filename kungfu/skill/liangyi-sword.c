// liangyi-sword.c (kunlun) 昆仑派正两仪剑法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action= ({ // 12 招
([	"action":"$N一式"HIC"「顺水推舟」"NOR"，$N手中$w指向自己左胸口，剑柄斜斜向右外，缓缓划向$n的$l",
	"lvl" : 0,
	"skill_name" : "顺水推舟"
]),
([	"action":"$N身形微侧，左手后摆，右手$w一招"HIY"「横扫千军」"NOR"，直向$n的腰间挥去",
	"lvl" : 10,
	"skill_name" : "横扫千军"
]),
([	"action":"$N纵身近前，$w斗然弯弯弹出，剑光爆长，一招"HIB"「峭壁断云」"NOR"，猛地刺向$n的胸口",
	"lvl" : 20,
	"skill_name" : "峭壁断云"
]),
([	"action":"$N左手捏个剑决，平推而出，决指上仰，右手剑朝天不动，一招"MAG"「仙人指路」"NOR"，刺向$n",
	"lvl" : 30,
	"skill_name" : "仙人指路"
]),
([	"action":"$N剑招忽变，使出一招"GRN"「雨打飞花」"NOR"，全走斜势，但七八招斜势中偶尔又挟着一招正势，教人极难捉摸",
	"lvl" : 40,
	"skill_name" : "雨打飞花"
]),
([	"action":"$N手中$w剑刃竖起，锋口向下，一招"BLU"「大漠平沙」"NOR"，剑走刀势，劈向$n的$l",
	"lvl" : 50,
	"skill_name" : "大漠平沙"
]),
([	"action":"$N一招"YEL"「木叶萧萧」"NOR"，$N横提$w，剑尖斜指向天，由上而下，劈向$n的$l",
	"lvl" : 60,
	"skill_name" : "木叶萧萧"
]),
([	"action":"$N抢前一步，$w微微抖动，剑光点点，一招"HIC"「江河不竭」"NOR"，终而复始，绵绵不绝刺向$n",
	"lvl" : 70,
	"skill_name" : "江河不竭"
]),
([	"action":"$N左手剑鞘一举，快逾电光石光，一招"HIW"「高塔挂云」"NOR"，用剑鞘套住$n手中兵器，$w直指$n的咽喉",
	"lvl" : 80,
	"skill_name" : "高塔挂云"
]),
([	"action":"$N翻身回剑，剑诀斜引，一招"HIM"「百丈飞瀑」"NOR"，剑锋从半空中直泻下来，罩住$n上方",
	"lvl" : 90,
	"skill_name" : "百丈飞瀑"
]),
([	"action":"$N一式"HIB"「雪拥蓝桥」"NOR"，$N手中剑花团团，一条白练疾风般向卷向$n",
	"lvl" : 100,
	"skill_name" : "雪拥蓝桥"
]),
([	"action":"$N腾空而起，突然使出一招"HIW"「无声无色」"NOR"，悄无声息地疾向$n的背部刺去",
	"lvl" : 130,
	"skill_name" : "无声无色"
]),
});

int valid_enable(string usage) { return (usage=="sword") || (usage=="parry"); }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 800)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 100)
		return notify_fail("你的玄天无极功火候太浅。\n");
	if ((int)me->query_skill("xunlei-sword", 1) < 80)
		return notify_fail("你的迅雷十六剑火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	int lvl = me->query_skill("liangyi-sword", 1);

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 35 || (int)me->query("neili") < 15 )
		return notify_fail("你的内力或气不够练两仪剑法。\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -5;
	int p_e2 = 10;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 60;
	int m_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("liangyi-sword", 1);
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
		"damage_type" : random(2) ? "劈伤" : "刺伤",
	]);
}
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"liangyi-sword/" + action;
}
/*mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int i;

	i=me->query_skill("liangyi-sword",1)/3;
	if(me->query_temp("ly_hebi")&& !me->query_temp("hebi_hit") 
		&& me->query_skill_mapped("parry") == "liangyi-sword")
	{
		me->set_temp("hebi_hit", 1);
		me->add_temp("apply/attack", i);
		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
		me->add_temp("apply/attack", -i);
		me->delete_temp("hebi_hit");
	}
}*/
void double_attack(object me, object victim)
{
		int i;

	i=me->query_skill("liangyi-sword",1)/3;
	if(me->query_temp("ly_hebi")&& !me->query_temp("hebi_hit") 
		&& me->query_skill_mapped("parry") == "liangyi-sword")
	{
		me->set_temp("hebi_hit", 1);
		me->add_temp("apply/attack", i);
		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
		me->add_temp("apply/attack", -i);
		me->delete_temp("hebi_hit");
	}
}
int help(object me)
{
	write(HIC"\n正两仪剑法："NOR"\n");
	write(@HELP

    正两仪剑法是昆仑派的高深剑法。
    倘若双剑合璧，两仪化四象，四象生八卦，阴阳相调，水火互
济，威力很强！

	学习要求：
		玄天无极功100级
		迅雷十六剑80级
		内力800
HELP
	);
	return 1;
}


