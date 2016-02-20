// jiujie-whip 九节鞭法
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N使一招"HIB"「怪蟒出洞」"NOR"，手中$w向上一扬，猛的对准$n的$l横扫过去",
	"lvl" : 0,
	"skill_name" : "怪蟒出洞",
]),
([	"action": "$N气运双臂，一招"BLU"「秋风飒飒」"NOR"$w幻出满天鞭影，虚虚实实地袭向$n的$l",
	"lvl" : 20,
	"skill_name" : "秋风飒飒",
]),
([	"action": "$N不慌不忙抡去$w，一招"MAG"「巨蟒腾空」"NOR"点点鞭影飘浮不定地点向$n的$l",
	"lvl" : 60,
	"skill_name" : "巨蟒腾空",
]),
([	"action": "$N手中$w在空中连连抖动，一招"MAG"「巨蟒翻身」"NOR"忽然狠狠向$n的$l打去！",
	"lvl" : 90,
	"skill_name" : "巨蟒翻身",
]),
([	"action": "$N将手中$w向下一沉，一招"HIG"「风卷残云」"NOR"从下向上往$n腰部卷去",
	"lvl" : 120,
	"skill_name" : "风卷残云",
]),
});

int valid_enable(string usage) { return (usage=="whip") || (usage=="parry"); }
int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力修为不足，没有办法练九节鞭法。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 20)
		return notify_fail("你的站桩功火候太浅。\n");
	if ( !objectp(weapon = me->query_temp("weapon")) ||
		( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练鞭法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("yijinjing", 1) < 10)
		return notify_fail("你的易筋经火候太浅。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力不够练九节鞭法。\n");
	me->receive_damage("qi",25);
 
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int d_e1 = -40;
	int d_e2 = -30;
	int p_e1 = 10;
	int p_e2 = 20;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 50;
	int m_e2 = 150;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jiujie-whip", 1);
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
		"damage_type" : random(2) ? "淤伤": "刺伤",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n九节鞭："NOR"\n");
	write(@HELP

    九节鞭是南少林入门鞭法。

	学习要求：
		站桩功50级
		内力修为100
HELP
	);
	return 1;
}

