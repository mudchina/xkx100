// chongling-sword.c
// Last Modified by Winder on May. 29 2001
// Modified by Venus Oct.2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N手中$w轻轻点击，使一招"GRN"「青梅如豆」"NOR"，向$n的$l刺去",
	"lvl"    : 0,
	"skill_name" : "青梅如豆"
]),
([	"action" : "$N手中$w轻轻掠过，斜斜削向$n额间。$n一呆，低声道：“"GRN "「柳叶似眉」"NOR"”",
	"lvl"    : 10,
	"skill_name" : "柳叶似眉"
]),
([	"action" : "$N舞动$w，一招"HIW"「雾中初见」"NOR"挟著无数剑光刺向$n的$l",
	"lvl"    : 20,
	"skill_name" :  "雾中初见"
]),
([	"action" : "$N手中$w轻轻挥洒，一招"HIB"「雨后乍逢」"NOR"直刺向$n的双眼",
	"lvl"    : 30,
	"skill_name" :   "雨后乍逢"
]),
([	"action" : "$N使一招"HIC"「一见钟情」"NOR"，手中$w剑光暴长，向$n的$l刺去",
	"lvl"    : 40,
	"skill_name" :   "一见钟情"
]),
([	"action" : "$N剑随身转，一招"HIM"「两小无猜」"NOR"罩向$n的$l",
	"lvl"    : 50,
	"skill_name" : "两小无猜"
]),
([	"action" : "$N手中$w剑光暴长，飞身而起，一招"MAG"「同生共死」"NOR"往$n咽喉刺去",
	"lvl"    : 60,
	"skill_name" :  "同生共死"
]),
([	"action" : "$N手中$w化成一道光弧，直指$n$l，一招"HIG"「难舍难分」"NOR"发出虎哮龙吟刺去",
	"lvl"    : 70,
	"skill_name" :   "难舍难分"
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力不够，没有办法练冲灵剑法。\n");
	if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
		return notify_fail("冲灵剑法必须配合紫霞神功才能练。\n");
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 10 )
		return notify_fail("你的内力或气不够，无法练习冲灵剑法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	write("你按着所学练了一遍冲灵剑法。\n");
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
	int d_e2 = 60;
	int p_e1 = 10;
	int p_e2 = 25;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 20;
	int m_e2 = 110;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("chongling-sword", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"chongling-sword/" + action;
}

int help(object me)
{
	write(HIC"\n冲灵剑法："NOR"\n");
	write(@HELP

    这是令狐冲和小师妹岳灵珊两人在华山练剑时共创的“冲灵剑
法”。“冲”是令狐冲，“灵”是岳灵珊，是二人好玩而共同钻研
出来的剑术。令狐冲的天份比师妹高得多，不论做甚么事都喜不拘
成法，别创新意，这路剑法虽说是二人共创，十之八九却是令狐冲
想出来的。当时二人武功造诣尚浅，这路剑法中也并没甚么厉害的
招式，只是二人常在无人处拆解，练得却十分纯熟。


	学习要求：
		紫霞神功1级
		内力修为50
HELP
	);
	return 1;
}

