// shenzhao-jing.c 神照经
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

mapping *action = ({
([	"action":"$N一跃跳到$n左侧，手肘撞处，击向$n上腹",
	"lvl": 0
]),
([	"action":"$N右手伸出，在$n臂膀上迅速无比的一按，$n一跤跌了出去",
	"lvl": 10
]),
([	"action":"$N大喝一声，双臂一举，便在同时，膝盖猛地上挺，撞向$n下裆",
	"lvl": 20
]),
([	"action":"$N猱身而上，双掌猛地拍向$n",
	"lvl": 30
]),
([	"action":"$N身体微侧，突然飞起一脚，踢向$n下三路。脚到中途，猛地一抬，踢向$n面门",
	"lvl": 40
]),
([	"action":"$N突然间左手一捺，封住$n退路，右手掌力汹涌而出",
	"lvl": 50
]),
});

int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "parry" || usage == "force";
}
int valid_learn(object me)
{
	object ding;
	if(!objectp(ding=present("ding dian",environment(me))) || !living(ding))
		return notify_fail("你必须得到丁典指导，才能学神照经。\n");
	if (me->query("cps")+me->query("cor") !=
		ding->query("cps")+ding->query("cor") )
		return notify_fail("丁典看了看你，喘息着道：我现在实在太累让我静会儿。\n");
	if ((me->query("kar")%4) > 0 )
		return notify_fail("丁典摇了摇头道：这门内功太过艰险了。不学也罢。\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("神照经只能用学(learn)的来增加熟练度。\n");
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -30;
	int p_e2 = 10;
	int f_e1 = 140;
	int f_e2 = 240;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shenzhao-jing", 1);
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

string exert_function_file(string func)
{
	return __DIR__"shenzhao-jing/" + func;
}
int help(object me)
{
	write(HIC"\n神照经："NOR"\n");
	write(@HELP

    丁典是荆门人，出生于武林世家。父母双亡，家财不少，却不
想结亲，只是勤于练武，结交江湖上的朋友。
    某次他乘船从四川下来，出了三峡后，船泊在三斗坪。晚上，
在船中听得岸上有打斗的声音。从窗中向外张望。那晚月光明亮，
看得清清楚楚，是三个人在围攻一个老者。一个是五云手万震山。
另一个是陆地神龙言达平。第三个人使一口长剑，身手甚是矫捷，
那是铁锁横江戚长发。老者便是铁骨墨萼梅念笙。他们的师父。梅
念笙受伤在先，抵敌不住三个徒弟的毒招，跳江而逃。
    丁典身边带得有金创药，救起梅念笙后，便替他治伤。可是他
背上那一剑刺得好深，穿通了肺，这伤是治不好的了。这么治了三
天，梅念笙从怀中取出一个油纸包来交给丁典，道：“我在这世上
的亲人，就这么三个徒儿。他们想夺我一部剑谱，可是没有剑诀，
那又有什么用？连城剑法虽然神奇，又怎及得上神照经了？这部神
照经，我送了给你，好好地练罢，此经若然练成，威力奇大，千万
不可误传匪人。”神照经，就是这样来的。

	学习要求：
		凭机缘向丁典学习
HELP
	);
	return 1;
}

