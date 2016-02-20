// shigu-bifa.c 石鼓打穴笔法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N一招"HIG"「指点江山」"NOR"，手中$w疾点向$n的期门穴!",
	"lvl" : 0,
	"skill_name" : "指点江山"
]),
([	"action": "$N吐气开声一招"HIB"「银钩铁划」"NOR"，$w如灵蛇吞吐，向$n白海穴戳去!",
	"lvl" : 9,
	"skill_name": "银钩铁划"
]),
([	"action": "$N向前跨上一步，混身充满战意，手中$w使出"CYN"「银瓶乍破」"NOR"，疾点$n的地仓穴!",
	"lvl" : 19,
	"skill_name" : "银瓶乍破"
]),
([	"action": "$N手中的$w自左而右地一晃，使出"BLU"「铁骑突出」"NOR"带着呼呼风声横打$n的章门穴!",
	"lvl" : 29,
	"skill_name": "铁骑突出"
]),
([	"action": "$N飞身跃起，一式"MAG"「龙耀九霄」"NOR"，卷起漫天笔影，$w向$n电射而去",
	"lvl" : 39,
	"skill_name": "龙耀九霄"
]),
([	"action": "$N凝气守中，$w逼出尺许雪亮笔锋，挥出"GRN"「灵台观景」"NOR"，一笔快似一笔地攻向$n",
	"lvl" : 59,
	"skill_name": "灵台观景"
]),
([	"action": "$N使出一招"HIW"「遥拜玉虚」"NOR"挺笔中宫直进，笔尖颤动，中途忽然转而向上变幻无方",
	"lvl" : 79,
	"skill_name": "遥拜玉虚"
]),
([	"action": "$N侧身斜刺一笔，一招"HIC"「天音萧煞」"NOR"卷带着呼呼笔风，将$n包围紧裹",
	"lvl" : 99,
	"skill_name": "天音萧煞"
]),
});

int valid_enable(string usage) { return usage == "dagger" || usage == "parry";}
int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力不够，没有办法练石鼓打穴。\n");
	if( (string)me->query_skill_mapped("force")!= "kuihua-xinfa")
		return notify_fail("石鼓打穴笔法需配合葵花心法。\n");
	if( (int)me->query_skill("kuihua-xinfa",1) < 20 )
		return notify_fail("你的葵花心法火候不够，还不能学习石鼓打穴笔法!\n");
	return 1;
}
int practice_skill(object me)
{
	object ob;
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "dagger" )
		return notify_fail("你必须先找一对判官笔才能学习石鼓打穴笔法。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够，没有办法练习石鼓打穴笔法。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -20);
//	write("你按著所学练了一遍石鼓打穴笔法。\n");
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
	int d_e1 = 0;
	int d_e2 = 20;
	int p_e1 = -40;
	int p_e2 = -30;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 400;
	int m_e2 = 600;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shigu-bifa", 1);
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
		"damage_type" : "刺伤",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__ "shigu-bifa/" + action;
}

int help(object me)
{
	write(HIC"\n石鼓打穴笔法："NOR"\n");
	write(@HELP

    日月神教黑木崖武功，梅庄三庄主秃笔翁看家本领，以判官笔
书写各名家碑帖，招招铁划银钩，沉猛有力。

	学习要求：
		葵花心法20级
		内力100
HELP
	);
	return 1;
}

