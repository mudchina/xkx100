// yueying-wubu.c 月影舞步
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$n身形一晃，纤腰一扭，一招"HIY"「星河鹭起」"NOR"，弹地而起。\n",
"$n一招"HIM"「歌尽桃花扇底风」"NOR"，$N只觉眼前一花，不见了$n的身影。\n",
"$n一招"HIC"「扫尽浮云风不定」"NOR"，身形微晃，有惊无险地避开了$N这一招。\n",
"只见$n身子向后一翻，一招"MAG"「缥渺孤鸿影」"NOR"，后荡而起，掠向一旁。\n" ,
"$n一招"HIG"「起舞弄清影」"NOR"，长袖翻飞，躲过$N这一招。\n",
"却见$n"GRN"「万顷江田一鹭飞」"NOR"，冲天而起，一波三折，端是美观。\n",
"可是$n一个"HIR"「流水落花春去也」"NOR"，侧身一让，$N这一招扑了个空。\n",
"只见$n一招"HIW"「月轮穿沼水无痕」"NOR"，倒掠身形，凌空两个翻转，退出两丈开外。\n",
"$n提气上升，意存玉枕，一招"HIB"「月在青天影在波」"NOR"，身子飘然而起。\n",
"$n面露淡淡的微笑，柳腰一转，一招"HIM"「月儿倒钩」"NOR"，不慌不忙的轻轻闪过$N的杀着。\n",
"$n口中轻唸"HIM"「轻问清风声，闻声不见人」"NOR"，一双金莲犹如幻化千百双，$N的眼前瞬间出现好
几个人的身影，不知道哪个才是真的。\n",
"只见$n裙角一摆，$n的身影已转到$N身后，并对着$N露出浅浅的一笑。\n",
"$n轻轻的原地旋转，舞出了"HIM"「落花散月，流水耀星」"NOR"，身子忽快忽慢，忽前忽后，实在是美
不胜收，只见$N呆呆站立，不晓得在想什么。\n",
"$n袖子轻掩嘴角，左手轻捻，一招"HIM"「麒麟天地行，凤凰开天际」"NOR"，舞出了月影舞步的精义
，$n身影轻轻地从$N的身边飘过。\n",
"但是$n不慌不忙，左脚轻抬，一式"HIM"「天马追月」"NOR"，$n的身影已出现在半空中，有如蝴蝶般，轻轻地飘落在$N身影的一丈外。\n",
"月影微步的奥义，"HIM"「行者莫不住一脚，听君轻唱仕女音」"NOR"，在$n的舞动下，有如一朵盛开的
鲜花，鲜艳的彩蝶。\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("bahuang-gong", 1) < 10 )
	return notify_fail("你的八荒六合唯我独尊功不够精熟，无法领会月影舞步。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 10|| (int)me->query("neili") < 2 )
		return notify_fail("你的体力太差了，不能练月影舞步。\n");
	me->receive_damage("qi", 10);
	me->add("neili", -2);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
string perform_action_file(string action)
{
	return __DIR__"yueying-wubu/" + action;
}

int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { 
	if (me->query("class")=="dancer") return 1.5;
	else return 1.0;
}

int help(object me)
{
	write(HIC"\n月影舞步："NOR"\n");
	write(@HELP

    月影舞步天山灵鹫宫轻功身法。

	学习要求：
	八荒六合唯我独尊功10级
HELP
	);
	return 1;
}

