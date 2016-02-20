// douzhuan-xingyi.c 斗转星移
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *parry_msg = ({
	YEL"蓦地里一股力道飞来，将$n一引一带，$n身子轻轻越起，身行落在一旁。\n"NOR,
	BLU"$n当下一股内力冲向$l，$N击向$n的$l的招数莫名奇妙的溜滑向一旁。\n"NOR,
	HIW"$n双手前探，左臂搭上$N右臂，右臂使出$N的招数将$N此招化去。\n"NOR,
	HIY"$n星移斗转，$N这招莫名其妙的在中途转了方向，直奔自己袭来。\n"NOR,
	YEL"$n作壁上观，双手与对方相交数掌，谈笑间竟使出$N成名技艺，使得$N不知如何是好。\n"NOR,
	BLU"$n凝神运气向$N猛攻快打，使出的招数好似$N的成名绝技，把$N的招数化于无行。\n"NOR,
	HIW"只见$n身如飘风，恰似漫天星移，诡异地一式，双掌动向无定不可捉摸地拍向$N的$l。\n"NOR,
	HIY"$n身行飘忽不定，在星移斗转之间反用$N的招数击向$N，却令人$N百思不得其解。\n"NOR,
	HIY"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n"NOR,
	HIY"$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n"NOR,
	HIY"$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n"NOR,
	HIY"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n"NOR,
});

int valid_enable(string usage) { return usage=="parry"; }
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}
int valid_learn(object me)
{
	object ob;
	int d_lvl = (int) me->query_skill("douzhuan-xingyi",1);
	int s_lvl = (int) me->query_skill("shenyuan-gong",1);
	int l_lvl = (int) me->query_skill("literate",1);

	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "姑苏慕容" ||
		myfam["master_id"] != "murong fu")
		return notify_fail("斗转星移只有向慕容公子学习。\n");
	if( (int)me->query("betrayer") > 0 )
		return notify_fail("你曾背叛师门，心志不纯，没有办法练斗转星移。\n");
	if( (int)me->query_int() < 40 )
		return notify_fail("你仔细地想了一会，还是没明白借力用力的道理。\n");
 	if( (int)me->query("max_neili") < 600 )
		return notify_fail("你的内力不够，没有办法练斗转星移。\n");
	if( s_lvl < 100)
		return notify_fail("斗转星移必须先学好神元功才能练习。\n");
	if( s_lvl + 30 < d_lvl)
		return notify_fail("你的神元功级别不够你真正领会更高级的斗转星移。\n");
	if( l_lvl + 50 < d_lvl)
		return notify_fail("你的读书写字水平不够你领会更高级的斗转星移。\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("斗转星移只能通过学习来提高。\n");
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"douzhuan-xingyi/" + action;
}
int help(object me)
{
	write(HIC"\n斗转星移："NOR"\n");
	write(@HELP

    姑苏慕容家最拿手的绝技，乃是一门借力打力之技，叫做“斗
转星移”。外人不知底细，见到慕容氏“以彼之道，还施彼身”神
乎其技，凡在致人死命之时，总是以对方的成名绝技加诸其身，显
然天下各门各派的绝技，姑苏慕容氏无一不会，无一不精。其实武
林中绝技千千万万，任他如何聪明渊博，决难将每一项绝技都学会
了，何况既是绝技，自非朝夕之功所能练成。但慕容氏有了这一门
巧妙无比的“斗转星移”之术，不论对方施出何种功夫来，都能将
之转移力道，反击到对方自身。出手的人武功越高，死法就越是巧
妙。慕容氏若非单打独斗，若不是有把握定能致敌死命，这“斗转
星移”的功夫便决不使用，是以姑苏慕容氏名震江湖，真正的功夫
所在，却是谁也不知。将对手的兵刃拳脚转换方向，令对手自作自
受，其中道理，全在“反弹”两字。便如有人一拳打在石墙之上，
出手越重，拳头上所受的力道越大，轻重强弱，不差分毫。只不过
转换有形的兵刃拳脚尚易，转换无形无质的内力气功，那就极难。

	学习要求：
                不叛师
                慕容复的嫡传弟子
		后天悟性40
		神元功100级
		神元功不能低于斗转星移30级
		读书写字不能低于斗转星移50级
		内力600
HELP
	);
	return 1;
}

