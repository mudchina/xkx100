// hengshan-jian.c 恒山剑法
/// Last Modified by sir on 5/17/2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N意带神闲，一式"HIG"「苍松迎客」"NOR"，$w轻轻飞动，幻起一片剑光，围掠$n全身",
	"lvl" : 0,
	"skill_name" : "苍松迎客"
]),
([	"action":"$N使一招"HIR"「拨云见日」"NOR"，身形向上飘起，手中$w虚虚实实幻出点点寒光射向$n$l",
	"lvl" : 20,
	"skill_name" : "拨云见日"
]),
([	"action":"$N身形一转，猛然一式"HIY"「日入空山」"NOR"，舞出满天剑影，挟着劲风向$n的$l扫去",
	"lvl" : 40,
	"skill_name" : "日入空山"
]),
([	"action":"$N仰天长笑，身形飘然而起，在半空中身子一旋，一式"HIB"「轻云蔽
月」"NOR"狂风般地击向$n",
	"lvl" : 50,
	"skill_name" : "轻云蔽月"
]),
([	"action":"$N左手捏着剑诀，右足踏开一招"HIC"「星划长空」"NOR"向上斜刺，长剑锵然跃出倏的化作几点星光射向$n的$l",
	"lvl" : 80,
	"skill_name" : "星划长空"
]),
([	"action":"$N向前迈去一大步，使出"HIW"「织女穿梭」"NOR"，手中$w舞成一个光球，迅若奔雷击向$n的$l",
	"lvl" : 100,
	"skill_name" : "织女穿梭"
]),
([	"action":"$N运力一抖$w，一时"MAG"「飘然出尘」"NOR"，$w幻出点点剑花，飘然刺向$n的$l",
	"lvl" : 110,
	"skill_name" : "飘然出尘"
]),
([	"action":"$N大喝一声，一招"GRN"「曲径通幽」"NOR"，$w闪电般划出一道大圆弧劈向$n的$l",
	"lvl" : 130,
	"skill_name" : "曲径通幽"
]),
([	"action":"$N身形向上飘起，突然一转身，头下脚上，手握$w，一招"HIM"「云霞
无声」"NOR"，无声无息地攻向$n的$l",
	"lvl" : 150,
	"skill_name" : "云霞无声"
]),
([	"action":"$N手中$w一抖，一招"BLU"「日照高林」"NOR"，$w逼出耀眼光芒，奋力击向$n的$l",
	"lvl" : 160,
	"skill_name" : "日照高林"
]),
([	"action":"$N忽然身形高高跃起，使出"RED"「云里乾坤」"NOR"，$w幻出漫天花瓣，迅如雷霆射向$n的$l",
	"lvl" : 180,
	"skill_name" : "云里乾坤"
])
});

int valid_enable(string usage) { return (usage=="sword") || (usage=="parry") ; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail(HIC"你的内力不够。\n"NOR);
	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("恒山剑法必须配合白云心法才能练。\n");
	if ((string)me->query("gender") != "女性" )
		return notify_fail(HIY"这种阴柔的剑法只有女子才适合学。\n"NOR);
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够练恒山剑法。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int d_e1 = 10;
	int d_e2 = 30;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 100;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hengshan-jian", 1);
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
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"hengshan-jian/" + action;
}

int help(object me)
{
	write(HIC"\n恒山剑法："NOR"\n");
	write(@HELP

    恒山剑法为恒山武功。

	学习要求：
		身具白云心法的女性
		内力100
HELP
	);
	return 1;
}

