// sanshou.c 岳家散手
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *msg = ({
"$N飞身跃起，半空中一脚踢向$n面门，却是个虚招。 \n说时迟那时快，只见$N一个倒翻，一招「过眼烟云」，双掌已到了$n的$l",
"$N使一招「尘土云月」，左拳虚晃右掌斜飞，击向$n的$l",
"$N一招「朝天阙」，斜步扭身，手肘猛地向$n的胸口撞去",
"$N左掌斜穿，右手前探做虎爪，一招「壮志饥餐」抓向$n的$l",
"$N的左手虚引额前，蓦地进步跟身，右手并指如剑，一招「笑谈渴饮」刺向$n的$l",
"$N提步上前，一记「莫等闲」，双掌缓缓推出，击向$n的前胸",
"$N脚踩七星方位，双掌翻飞施出「潇潇雨歇」，无数掌影击向$n的$l",
"$N大喝一声，一招「怒发冲冠」，双掌带着天罡正气，迅捷无比的击向$n的$l",
"$N左手递出，长臂竟如残月般弯转，一招「从头收拾旧山河」右手反手对准$n$l扎去",
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="changquan"; }

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练岳家散手必须空手。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("jing") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("neili") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);

	return 1;
}
mapping query_action(object me, object weapon)
{
	return ([
		"action" : msg[random(sizeof(msg))],
		"dodge"  : -30+random(30),
		"parry"  : 30+random(30),
		"force"  : 50+random(100),
		"damage_type" : random(2)?"内伤":"瘀伤",
	]);
}

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n岳家散手："NOR"\n");
	write(@HELP

    【岳家散手】又称岳氏散手、岳氏散掌，属于岳家拳。据考证，
宋代著名抗金将领岳飞曾创编子母拳，后其子岳震、岳霆隐居于湖北
黄梅，传下了岳家拳。金元时期，禁止练武，传统武术受到摧残，岳
家拳也难幸免。降至明清，武术鼎盛，岳家拳才得以发展。史料记载，
明末清初的武术家访名师于终南山，得岳武穆拳谱，据其拳理创编形
意拳而自成一派。后来岳家拳主要流行于河北一带。清末河北雄县人
刘侍俊任宫廷护卫神机军营教官，曾教授“岳氏散手”。岳氏散手共三
十二路一百七十三手，主要特点为以静待动，以快制胜，出手凶猛，
见缝插针。强调心雄胆大，勇猛果断，出手狠毒，迅疾飞快。平常对
指头功夫要求很严，交手时不讲情面，人称一毒，二狠，三快。岳家
散手的主要方法，有刁卡挤靠、劈打捆肘等，每一手法都有一连串的
接应手法，“手起足要落，足落手要起”，或手打，或肘顶肩撞，一环
扣一环，随机生变，贴身进步，见缝插针。


	学习要求：
		无
HELP
	);
	return 1;
}