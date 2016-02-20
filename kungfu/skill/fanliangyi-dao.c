// fanliangyi-dao.c 反两仪刀法
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N手中$w斜指，一招"HIY"「混沌一破」"NOR"，反身一顿，一刀向$n的$l撩去",
	"lvl"    : 0,
	"skill_name" : "混沌一破",
]),
([	"action" : "$N一招"HIC"「太乙生萌」"NOR"，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
	"lvl"    : 20,
	"skill_name" : "太乙生萌",
]),
([	"action" : "$N展身虚步，提腰跃落，一招"BLU"「两仪合德」"NOR"，刀锋化作两股斩向$n",
	"lvl"    : 40,
	"skill_name" : "两仪合德",
]),
([	"action" : "$N一招"HIW"「日月晦明」"NOR"，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
	"lvl"    : 60,
	"skill_name" : "日月晦明",
]),
([	"action" : "$N手中$w一沉，一招"HIR"「无色无相」"NOR"，双手持刃拦腰反切，砍向$n的胸口",
	"lvl"    : 80,
	"skill_name" : "无色无相",
]),
([	"action" : "$N挥舞$w，使出一招"HIB"「万劫不复」"NOR"，上劈下撩，左挡右开，齐齐罩向$n",
	"lvl"    : 100,
	"skill_name" : "万劫不复",
])
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 50)
		return notify_fail("你的「紫霞神功」火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if( !me->query_skill("zixia-shengong",1))
		return notify_fail("练「反两仪刀法」必须要以「紫霞神功」为基础。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练「反两仪刀法」。\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = 55;
	int d_e2 = 30;
	int p_e1 = 0;
	int p_e2 = -15;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 50;
	int m_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("fanliangyi-dao", 1);
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
		"damage_type" : "割伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point() { return 1; }
string perform_action_file(string action)
{
	return __DIR__"fanliangyi-dao/" + action;
}
/*
int form_array(object leader)
//int perform(object leader, object target)
{
	object *member,ob, weapon;
	int i,j,n;
	int max,min,skill;

	member = leader->query_team();
	if( sizeof(member) != 2 )
		return notify_fail("反两仪刀共需两人，少一个多一个都不行。\n");

	j=sizeof (member);
	for (i=0;i<j;i++)
	{
		ob=member[i];
		if (!ob || !living(ob) || ob->query_temp("noliving") ||
			!ob->is_character())
		{
			return notify_fail("你想和谁同使反两仪刀？\n");
		}
		if (ob->query_temp("array/name"))
		{
			return notify_fail("已经组成刀阵了。\n");
		}
		if (environment(leader)!=environment(ob))
		{
			return notify_fail("人数不够两人。\n");
		}
		if (!ob->query_skill("fanliangyi-dao",1))
		{
			return notify_fail(ob->name()+"还不会反两仪刀法。\n");
		}
		if (ob->is_ghost())
		{
			return notify_fail("只有阳间的人才能组刀阵。\n");
		}

		if( (int)ob->query("max_neili") < 50 )
			return notify_fail(ob->query("name")+"的内力不够。\n");

		if( (string)ob->query_skill_mapped("force")!= "zixia-shengong")
			return notify_fail(ob->query("name")+"没有使用华山派内功。\n");

		if( !(weapon = ob->query_temp("weapon"))
			|| (string)weapon->query("skill_type") != "blade" )
			return notify_fail(ob->query("name")+"必须拿把刀做武器。\n");

		if( (int)ob->query_skill("fanliangyi-dao",1)<30)
			return notify_fail(ob->query("name")+"的反两仪刀法还不够熟练。\n");

		if( (string)ob->query_skill_mapped("blade")!="fanliangyi-dao")
			return notify_fail(ob->query("name")+"必须使用反两仪刀法。\n");

	}

//get the average array skill of the team
	n=0;
	for (i=0;i<j;i++)
	{
		ob=member[i];
		n+=(int)ob->query_skill("fanliangyi-dao",1);
	}
	n/=2;

//get the difference of the array skill,
//first get the max and mix skill level of the array
	max=member[0]->query_skill("fanliangyi-dao",1);
	min=max;
	for (i=0;i<j;i++)
	{
		skill=member[i]->query_skill("fanliangyi-dao",1);
		if(skill>max)
			max=skill;
		else if(skill<min)
			min=skill;
	}

//and the leader is important
	n += leader->query_skill("fanliangyi-dao", 1) * 5;
	n /= max - min + 1;
	for (i=0;i<j;i++)
	{
		ob=member[i];
		ob->set_temp("no_quit",1);

		ob->set_temp("array/name","fanliangyi-dao");
		ob->set_temp("array/level",n);

		ob->add_temp("apply/attack",n);
		ob->add_temp("apply/defense", n);
		ob->add_temp("apply/damage",n);
		ob->add_temp("apply/armor", n);
	}
	message_combatd(HIG"$N率领$N站定两仪方位，顿时两人之间显得浑然天成、毫无破绽。\n" NOR, leader);
	return 1;
}
int dismiss_array(object person)
{
	int i,j,n;
	object *member,ob;

	member = person->query_team();
	j=sizeof(member);
	n=person->query_temp("array/level");
	for (i=0;i<j;i++)
	{
		ob=member[i];
		ob->delete_temp("array");
		ob->add_temp("apply/attack",-n);
		ob->add_temp("apply/damage",-n);
		ob->add_temp("apply/defense",-n);
		ob->add_temp("apply/armor", -n);
		tell_object(ob,"刀阵解散了\n");
	}
}

//if the leader kills enemy, then all members in the array kill enemy
int array_kill(object leader, object enemy)
{
	object *member, ob;
	int i,j;
	member=leader->query_team();
	j=sizeof(member);

	for(i=0;i<j;i++)
	{
		ob=member[i];
		ob->kill_ob(enemy);
	}

	return 1;
}
int effective_level() { return 10;}
*/
int help(object me)
{
	write(HIC"\n反两仪刀法："NOR"\n");
	write(@HELP

    反两仪刀法是华山派功夫，两仪化四象，四象化八卦，正变八
八六十四招，奇变八八六十四招，正奇相合，六十四再以六十四倍
之，共有四千零九十六种变化。天下武功变化之繁，可说无出其右
了。招数虽多，终究不脱于太极化为阴阳两仪的道理。阳分太阳、
少阴，阴分少阳、太阴，是为四象。太阳为乾兑，少阴为离震，少
阳为巽坎，太阴为艮坤。乾南、坤北、离东、坎西、震东北、兑东
南、巽西南、艮西北。自震至乾为顺，自巽至坤为逆。天地定位，
山泽通气，雷风相薄，水火不相射，八卦相错。数往者顺，知来者
逆。正两仪剑法，是自震位至乾位的顺；华山派反两仪刀法，则是
自巽位至坤位的逆。

	学习要求：
		紫霞神功50级
		内力300
HELP
	);
	return 1;
}

