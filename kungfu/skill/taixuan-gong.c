// taixuan-gong.c 侠客岛太玄功
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

string *dodge_msg = ({
	"$n左手拍出，劲风到处，把$N震到一边。\n",
	"$n手臂回转，抓住$N手肘一推，将$N远远掷开。\n",
	"$n两腿轻蹬，激跃而出，竟已落在十数丈外。\n",
	"$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了。\n",
});

mapping *action = ({
([	"action":"$N双手一举，一股劲气澎湃汹涌而来，逼得$n踉踉后退",
	"lvl": 0
]),
([	"action":"$N右手伸出，在$n臂膀上迅速无比的一按，$n一跤跌了出去",
	"lvl": 10
]),
([	"action":"$N大喝一声，张口一股内气向$n脸上喷去",
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
	return usage == "unarmed" || usage == "dodge" || usage == "parry" || usage == "force";
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = 10;
	int f_e1 = 440;
	int f_e2 = 600;	
	int i, lvl, seq, ttl = sizeof(action);
	if (random(me->query_skill("taixuan-gong",1)) > 220 && me->query("neili") > 100)
	{
		me->add("neili", -50);
		return ([
	"action": HIR "$N的心中突然一片茫然，只觉得经脉中象有无数的蝌蚪在串来串去，难过非常，
当下不及多想，顺着蝌蚪的走向一阵拳打脚踢！四周顿时劲风乱飑，好不热闹！"NOR,
//	"damage": 1000,
  "parry" : -80,
  "dodge" : -40,
	"force" : 1000,
	"damage_type": "瘀伤"]);
	}
	lvl = (int) me->query_skill("taixuan-gong", 1);
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

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
	return notify_fail("你想领会太玄功，只能到侠客岛去面壁。\n");
}
string exert_function_file(string func)
{
	return __DIR__"taixuan-gong/" + func;
}
int help(object me)
{
	write(HIC"\n太玄功："NOR"\n");
	write(@HELP

    太玄功源自侠客岛上洞壁武功。

	学习要求：
		各人自己的福缘
HELP
	);
	return 1;
}

