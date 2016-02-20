// Last Modified by winder on May. 29 2001
// qianye-shou.c 如来千叶手 和韦陀掌互备 截自《佛展千手法》。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIR"「两手结印」"NOR"，双手抬起，手心向上，两大拇指指尖轻轻接触，向前架起",
	"lvl"   : 0,
	"skill_name" : "两手结印"
]),
([	"action" : "$N以手印势抬起，向上转掌，一式"YEL"「弥勒伸腰」"NOR"，全身逐渐抻直，双手向$n的方向晃出",
	"lvl"   : 10,
	"skill_name" : "弥勒伸腰"
]),
([	"action" : "$N一式"CYN"「如来灌顶」"NOR"，两手同时向外转掌，以手成漏斗状，接着伸腕落掌，下落$n顶门",
	"lvl"   : 20,
	"skill_name" : "如来灌顶"
]),
([	"action" : "$N提起两手到胸前，渐渐"BLU"「双手合十」"NOR"，跟着手心空开，两肘架起来，两小臂成一直线直挥$n",
	"lvl"   : 30,
	"skill_name" : "双手合十"
]),
([	"action" : "$N使一式"HIC"「掌指乾坤」"NOR"，两掌松开转掌，左手立指在胸前，右手却掌心向下，拍向$n$l",
	"lvl"   : 40,
	"skill_name" : "掌指乾坤"
]),
([	"action" : "$N一式"HIY"「金猴分身」"NOR"，两手由胸前拉开向两侧伸展，与$n肩平，接着向两边用力一甩",
	"lvl"   : 50,
	"skill_name" : "金猴分身"
]),
([	"action" : "$N两手一边分开，一边向前下方伸展，一式"MAG"「双龙下海」"NOR"，手臂变幻，在$n胸前印了不下十掌",
	"lvl"   : 60,
	"skill_name" : "双龙下海"
]),
([	"action" : "$N一式"CYN"「菩萨扶莲」"NOR"，全身逐渐抻直，手指尖向$n力点，然后全身立即放松，两手恢复到胸前合十",
	"lvl"   : 70,
	"skill_name" : "菩萨扶莲"
]),
([	"action" : "$N一式"HIG"「罗汉背山」"NOR"，两手一边分开，一边向$n体后伸展，同时两掌心转向后方，将$p摔了出去",
	"lvl"   : 80,
	"skill_name" : "罗汉背山"
]),
([	"action" : "$N一式"HIM"「金刚排山」"NOR"，指尖向上，臂与肩同高，当臂伸直后，用力一抻，向$n立掌推出",
	"lvl"   : 90,
	"skill_name" : "金刚排山"
]),
([	"action" : "$N两手缓缓下落，并将掌心转向$n腹部，一式"GRN"「叠扣小腹」"NOR"，两手重叠，猛地放劲",
	"lvl"   : 100,
	"skill_name" : "叠扣小腹"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo){ return combo=="weituo-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练如来千叶手必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 20)
		return notify_fail("你的站桩功火候不够，无法学如来千叶手。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练习如来千叶手。\n");
	if (me->query_skill("fengyun-hand", 1) < 20 ||
		me->query_skill("luohan-cuff", 1) < 20)
		return notify_fail("你还未掌握风云手和罗汉拳，无法学习如来千叶手。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练如来千叶手。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -25);
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
	int d_e1 = -45;
	int d_e2 = -15;
	int p_e1 = 15;
	int p_e2 = 45;
	int f_e1 = 150;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qianye-hand", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	 return __DIR__"qianye-hand/" + action;
}

int help(object me)
{
	write(HIC"\n如来千叶手："NOR"\n");
	write(@HELP

    如来千叶手是南少林手法，和韦陀掌互备。出自《佛展千手法》。

	学习要求：
		站桩功20级
		罗汉拳20级
		风云手20级
		内力修为50
HELP
	);
	return 1;
}

