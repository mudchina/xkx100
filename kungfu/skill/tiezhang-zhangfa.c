// tiezhang-zhangfa.c 铁掌掌法
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N右掌一拂而起，一招"CYN"「推窗望月」"NOR"，自侧面连消带打，登时将$n的力道带斜。",
	"lvl"    : 0,
	"skill_name" : "推窗望月"
]),
([	"action" : "$N使一招"YEL"「分水擒龙」"NOR"，左掌陡然沿着伸长的右臂，飞快的一削而出，斩向$n的$l",
	"lvl"    : 10,
	"skill_name" : "分水擒龙"
]),
([	"action" : "$N突然使一式"HIW"「白云幻舞」"NOR"，双臂如旋风一般一阵狂舞，刮起一阵旋转的气浪。 ",
	"lvl"    : 20,
	"skill_name" : "白云幻舞"
]),
([	"action" : "$N一招"HIY"「掌中乾坤」"NOR"，猛地侧过身来，右臂自左肋下疾翻而出，拇，中两指扣圈猛弹$n的$l",
	"lvl"    : 30,
	"skill_name" : "掌中乾坤"
]),
([	"action" : "$N一招"RED"「落日赶月」"NOR"，伸掌一拍一收，一拍无丝毫力道，一收之间，一股阴柔无比的力道才陡然发出。",
	"lvl"    : 40,
	"skill_name" : "落日赶月"
]),
([	"action" : "$N身行暴起，一式"BLU"「蛰雷为动」"NOR"，双掌横横切出，掌缘才递出，呜呜呼啸之声狂作。",
	"lvl"    : 50,
	"skill_name" : "蛰雷为动"
]),
([	"action" : "$N一招"MAG"「天罗地网」"NOR"，左掌大圈而出，右掌小圈而出，两股奇异的力道一会之下，击向$n的$l",
	"lvl"    : 60,
	"skill_name" : "天罗地网"
]),
([	"action" : "$N一招"HIG"「五指幻山」"NOR"，猛一吐气，单掌有如推门，另一掌却是迅疾无比的一推即收。",
	"lvl"    : 80,
	"skill_name" : "五指幻山"
]),
([	"action" : "$N突然大吼一声，一招"HIR"「猛虎下山」"NOR"身行疾飞而起，猛向$n直扑而下，空气中暴出“呜”的一声刺耳尖啸。",
	"lvl"    : 100,
	"skill_name" : "猛虎下山"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练铁掌掌法必须空手。\n");
	if ((int)me->query_skill("guiyuan-tunafa", 1) < 100)
		return notify_fail("你归元吐呐法火候不够，无法练铁掌掌法。\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不够，无法练铁掌掌法。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练铁掌掌法。\n");
	if (me->query_skill("tiezhang-zhangfa", 1) < 50)
		me->receive_damage("qi", 60);
	else
		me->receive_damage("qi", 55);
	me->add("neili", -35);
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
	int d_e1 = -55;
	int d_e2 = -30;
	int p_e1 = -10;
	int p_e2 = 15;
	int f_e1 = 300;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tiezhang-zhangfa", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tiezhang-zhangfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lev,damage, i;
	string msg;
	object weap;
	object piece;
	weap = victim->query_temp("weapon");
	lev =me->query("tiezhang-zhangfa");

	if( (me->query("neili") > 1000) &&
		(victim->query_temp("weapon")) &&
		(me->query_temp("tzzf")) &&
		(random(me->query_str()) > victim->query_str()/2) )
	{	
		if (random((int)weap->query("rigidity")) <3)
		{
			message_combatd(HIW"$N运掌如刀，连击三十六下，只听见「啪」地一声，$n手中的" + weap->name() + "已经断为两截！\n" NOR, me, victim );
			seteuid(getuid());
			piece = new("/clone/misc/piece");
			piece->set_name("断掉的" + weap->query("name"),({weap->query("id"),"piece"}));
			piece->move(environment(me));
			destruct(weap);
		}
		else
		{
			message_combatd(HIW"$N运掌如刀，连击三十六下，只听见「当」地一声，$n手中的" + weap->name() + "被刀气震落到地上！\n" NOR, me,victim );
			weap->move(environment(me));
		}
		victim->reset_action();
		me->add("neili", -100);
		return 1;
	}
}

int help(object me)
{
	write(HIC"\n铁掌掌法："NOR"\n");
	write(@HELP

    铁掌掌法是铁掌帮镇帮掌法。
    铁掌掌力浑厚恶毒，与降龙十八掌、黯然销魂掌并称天下。


	学习要求：
		归元吐纳法100级
		内力修为1000
HELP
	);
	return 1;
}

