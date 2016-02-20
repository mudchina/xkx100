// anying-fuxiang.c 
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$n一个"HIC"「月上柳梢头」"NOR"，出白虎门，入天地门，随着$N的攻势飘起，从容躲过此招。\n",
"$n使一招"HIM"「大漠孤烟直」"NOR"，出青龙门，入风云门，猛然纵起丈余，结果$N扑了个空。\n",
"$n身形一摇，幻出几个人影，出天地门，入青龙门，一招"BLU"「碎影舞斜阳」"NOR"躲过$N的攻势。\n",
"$n一招"HIM"「燕子三抄水」"NOR"纵身跃起，出风云门，入玄武门，倏忽已落至$N身后。\n",
"$n左一摇，右一晃，出玄武门，入朱雀门，一招"HIW"「云深不知处」"NOR"已轻松闪过。\n",
"$n双足一点，斜斜飞起，出朱雀门，入白虎门，使出"HIM"「斜日杏花飞」"NOR"，已闪到$N身侧。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("bibo-shengong", 1) < 10 )
	return notify_fail("你的碧波神功不够精熟，无法领会暗影浮香。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30|| (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，不能练暗影浮香。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -6);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.3; }

int help(object me)
{
	write(HIC"\n暗影浮香："NOR"\n");
	write(@HELP

    桃花岛的独门轻功身法。

	学习要求：
	   碧波神功 10 级 	
HELP
	);
	return 1;
}

