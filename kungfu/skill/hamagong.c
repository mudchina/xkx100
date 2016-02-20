// hamagong.c 蛤蟆功
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

mapping *action = ({
([	"action" : "$N忽而倒竖，一手撑地，身子横挺，只以一掌向$n的$l拍出",
	"lvl" : 0,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N双手在地上一撑，身子忽地拔起，一跃三尺，落在$n的面前，单掌向$p直劈而下",
	"lvl" : 10,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N突然伸手在自己脸上猛抓一把，又反足在自己肾上狠踢一脚，一掌击出，中途方向必变，实不知将打何处",
	"lvl" : 20,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "突然之间，$N俯身疾攻，上盘全然不守，微微侧头，一口唾沫往$n$l吐去",
	"lvl" : 30,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N丝毫不动声色，双腿微曲，右掌平伸，左掌缓缓运起蛤蟆功的劲力，呼的一声推向$n",
	"lvl" : 80,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N默念口诀运气经脉，只觉愈转愈是顺遂，当下一个翻身跃起，咕的一声叫喊，双掌对着$n拍出",
	"lvl" : 110,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "但见$N双腿微曲，双掌会收，然后向$n一上一下，一放一收，斗然击出",
	"lvl" : 140,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N闭眼逼住呼吸，过了片刻，猛跃而起，眼睛也不及睁开，双掌便向$n的方向推了出去",
	"lvl" : 170,
	"skill_name" : "蛤蟆功"
]),
([	"action" : "$N脚步摇摇幌幌的看上去马上就会跌倒，忽然双腿一弯、一登，口中阁的一声叫喝，手掌向$n猛然推出",
	"lvl" : 199,
	"skill_name" : "蛤蟆功"
]),
});
/*
mapping *action = ({
([	"action": "$N轻身一跃，使出一招" + HIY"「沙漠孤舟」"NOR + "，左掌横，右掌带，将$n逼开。",
	"force" : 200,
	"dodge" : 20,
	"damage": 240,
	"skill_name": "沙漠孤舟",
	"damage_type": "瘀伤"
]),
([	"action":"只见$N倏地向前跨出一步，一招" + WHT"「万里独归」"NOR + "，双掌一错，顺势攻向$n",	
	"force" : 220,
	"dodge" : 20,
	"damage": 250,
	"skill_name": "万里独归",
	"damage_type": "瘀伤"
]),
([	"action":"$N一招" + HIW"「鸣沙寒烟」"NOR + "，来势曼妙无方，掌力微吐，罩向$n周身。",
	"force" : 400,
	"dodge" : 30,
	"damage": 250,
	"skill_name": "鸣沙寒烟",
	"damage_type": "瘀伤"
]),
([	"action":"$N低眉曲身，掌势若有若无，恰恰将$n来招一一封住，并暗含反击之意，正是一招" + HIR"「霓裳弄雪」"NOR + "。",
	"force" : 225,
	"dodge" : 30,
	"damage": 270,
	"skill_name": "霓裳弄雪",
	"damage_type": "瘀伤"
]),
([	"action":"$N一招" + HIB"「秋恨客途」"NOR + "，抽身提步，不退反进，双掌平推，来如电闪，径直拍向$n。",
	"force" : 530,
	"dodge" :-20,
	"damage": 300,
	"skill_name": "秋恨客途",
	"damage_type": "瘀伤"
]),
});
*/

int valid_enable(string usage) { return usage == "force"||usage == "strike"; }
int valid_combine(string combo) { return combo=="shexing-diaoshou"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("hamagong", 1);
	int t = 1, j;
	mapping myfam;
	
	myfam = (mapping)me->query("family");
/*
	if(!myfam || myfam["family_name"] != "白驼山派"|| myfam["master_id"] != "ouyang feng")
		return notify_fail("蛤蟆功乃不世神功，须向欧阳锋亲自求教。\n");
*/
	if( i <= 100) for (j = 1; j < i / 10; j++) t*= 2;

	if ( me->query("gender") == "无性" && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的蛤蟆功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学蛤蟆功。\n");

	if(i<=100)
	{
		if (i > 10 && -(int)me->query("shen") < t * 100) 
			return notify_fail("学蛤蟆功，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	}
	else
	{
		if (-(int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("学蛤蟆功，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	}
	return valid_public(me);
}
int practice_skill(object me)
{
	return notify_fail("蛤蟆功只能用学(learn)的来增加熟练度。\n");
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
	int d_e1 = -40;
	int d_e2 = -20;
	int p_e1 = 0;
	int p_e2 = 30;
	int f_e1 = 190;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hamagong", 1);
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
	return __DIR__"hamagong/" + func;
}
string perform_action_file(string action)
{
	return __DIR__"hamagong/" + action;
}

int help(object me)
{
	write(HIC"\n蛤蟆功："NOR"\n");
	write(@HELP

    欧阳锋创立此功，为白驼山派本门内功。此功也可作为掌法使
用，并能与蛇形刁手互备。
    这蛤蟆功纯系以静制动，他全身涵劲蓄势，蕴力不吐，只要敌
人一施攻击，立时便有猛烈无比的劲道反击出来，刚猛无匹。

	学习要求：
		基本内功10级
		太监无法领悟50级以上的蛤蟆功
		相应的戾气
HELP
	);
	return 1;
}

