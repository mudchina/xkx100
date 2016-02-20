// yunv-jian.c 玉女剑法
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action" : "$N一招"+(order[random(13)])+"「雁行斜击」"NOR"，身形斜飞，手中$w轻轻点向$n的$l",
	"lvl" : 0,
	"skill_name" : "雁行斜击"
]),
([	"action" : "$N长跃而起，"+(order[random(13)])+"「白虹经天」"NOR"，$w猛然下刺",
	"lvl" : 4,
	"skill_name" :  "白虹经天"
]),
([	"action" : "$N使出"+(order[random(13)])+"「浪迹天涯」"NOR"，挥剑直劈，威不可当",
	"lvl" : 9,
	"skill_name" :  "浪迹天涯"
]),
([	"action" : "$N使"+(order[random(13)])+"「花前月下」"NOR"一招自上而下搏击，模拟冰轮横空、清光铺地的光
景",
	"lvl" : 14,
	"skill_name" :  "花前月下"
]),
([	"action" : "$N手中$w颤动，一招"+(order[random(13)])+"「鲜花招展」"NOR"来回挥削，只幌得$n眼花撩乱，浑不知从
何攻来",
	"lvl" : 19,
	"skill_name" :  "鲜花招展"
]),
([	"action" : "$N使出"+(order[random(13)])+"「清饮小酌」"NOR"剑柄提起，剑尖下指，有如提壶斟酒，直挥$n的
$l",
	"lvl" : 24,
	"skill_name" :  "清饮小酌"
]),
([	"action" : "$N手中$w由内自外一刺，左手如斟茶壶，使出"+(order[random(13)])+"「扫雪烹茶」"NOR"来",
	"lvl" : 29,
	"skill_name" :  "扫雪烹茶"
]),
([	"action" : "$N左掌横摆胸前，右手中$w轻轻挥拂，却是一招"+(order[random(13)])+"「抚琴按萧」"NOR"",
	"lvl" : 34,
	"skill_name" :  "抚琴按萧"
]),
([	"action" : "$N一招"+(order[random(13)])+"「松下对弈」"NOR"，$w自右向左挥一个大弧，刺向$n的$l",
	"lvl" : 39,
	"skill_name" :  "松下对弈"
]),
([	"action" : "$N左手如拂五弦，竟以掌为剑攻向$n，却是一招"+(order[random(13)])+"「池边调鹤」"NOR"",
	"lvl" : 44,
	"skill_name" :  "池边调鹤"
]),
([	"action" : "$N一招"+(order[random(13)])+"「柳絮风飘」"NOR"，$w轻灵地划出几个圆弧，向$n的$l挥去",
	"lvl" : 49,
	"skill_name" :  "柳絮风飘"
]),
([	"action" : "$N一招"+(order[random(13)])+"「小园艺菊」"NOR"，手中$w迅疾向$n的下盘连点三点",
	"lvl" : 54,
	"skill_name" :  "小园艺菊"
]),
([	"action" : "$N使出"+(order[random(13)])+"「西窗夜话」"NOR"，手中$w中宫直入，攻向$n的$l",
	"lvl" : 59,
	"skill_name" :  "西窗夜话"
]),
([	"action" : "$N脚下左高右低，一招"+(order[random(13)])+"「柳荫联句」"NOR"，$w在空中化成一道光环，急攻
$n",
	"lvl" : 64,
	"skill_name" :  "柳荫联句"
]),
([	"action" : "$N手中$w由下而上卷起，犹如打起竹帘一般，却是"+(order[random(13)])+"「竹帘临池」"NOR"",
	"lvl" : 70,
	"skill_name" :  "竹帘临池"
]),
([	"action" : "$N做搭弓射箭状，一招"+(order[random(13)])+"「木兰射雁」"NOR"，右手$w直刺$n的$l",
	"lvl" : 76,
	"skill_name" :  "木兰射雁"
]),
([	"action" : "$N左手剑诀一领，右手$w平平刺向$n的$l，是一招"+(order[random(13)])+"「双蝶迷回」"NOR"",
	"lvl" : 82,
	"skill_name" :  "双蝶迷回"
]),
([	"action" : "$N手中$w合身疾刺，一招"+(order[random(13)])+"「孤云出釉」"NOR"，直指$n的$l",
	"lvl" : 88,
	"skill_name" : "孤云出釉"
]),
([	"action" : "$N一招"+(order[random(13)])+"「幽兰空谷」"NOR"，$w看似随意地一挥，从$n不可思议的角度攻入
",
	"lvl" : 94,
	"skill_name" :  "幽兰空谷"
]),
([	"action" : "$N使出"+(order[random(13)])+"「茶花满路」"NOR"，一时间空中尽是$w的影子，令$n不知如何抵挡
",
	"lvl" : 100,
	"skill_name" :  "茶花满路"
]),
([	"action" : "$N一招"+(order[random(13)])+"「陌路采桑」"NOR"，$w连点数点，疾刺$n的$l",
	"lvl" : 99,
	"skill_name" :  "陌路采桑"
]),
([	"action" : "$N突然盘蹲下来，一招"+(order[random(13)])+"「秋雨萧萧」"NOR"，$w自下而上刺向$n",
	"lvl" : 106,
	"skill_name" :  "秋雨萧萧"
]),
([	"action" : "$N错开脚步，手中$w突然从自己的肋下刺出，却是一招"+(order[random(13)])+"「琴心剑胆」"NOR"
",
	"lvl" : 112,
	"skill_name" :  "琴心剑胆"
]),
([	"action" : "$N犹如在水面滑行一般，一招"+(order[random(13)])+"「池塘秋夜」"NOR"，平平地向$n的$l挥去",
	"lvl" : 118,
	"skill_name" :  "池塘秋夜"
]),
([	"action" : "$N一招"+(order[random(13)])+"「皓腕玉镯」"NOR"，手中$w刺点$n的手腕",
	"lvl" : 124,
	"skill_name" :  "皓腕玉镯"
]),
([	"action" : "$N一招"+(order[random(13)])+"「牡丹含泪」"NOR"，$w绕出数个银圈，平平地向$n的$l卷去",
	"lvl" : 131,
	"skill_name" :  "牡丹含泪"
]),
([	"action" : "$N左脚轻点地面，身形往前一扑，一招"+(order[random(13)])+"「芍药蕴珠」"NOR"，$w向$n的$l刺
去",
	"lvl" : 138,
	"skill_name" :  "芍药蕴珠"
]),
([	"action" : "$N一招"+(order[random(13)])+"「檐前飞燕」"NOR"，身形跃起，手中$w扫向$n的$l",
	"lvl" : 145,
	"skill_name" :  "檐前飞燕"
]),

([	"action" : "$N脸现黯然之色，随意一招"+(order[random(13)])+"「蒹葭苍苍」"NOR"，$w刺向$n的$l",
	"lvl" : 159,
	"skill_name" :  "蒹葭苍苍"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("yunv-xinfa", 1) < 15)
		return notify_fail("你的玉女心法火候不到，无法学习玉女剑法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 55)
		return notify_fail("你的体力不够练玉女剑法。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不足以练玉女剑法。\n");
	me->receive_damage("qi", 50);
	me->add("neili", -35);
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
	int d_e1 = -20;
	int d_e2 = 5;
	int p_e1 = -45;
	int p_e2 = -30;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 180;
	int m_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yunv-jian", 1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { 
	if (me->query("gender")== "女性")
	return 1.0; 
	else
	return 0.7;
	}

string perform_action_file(string action)
{
	return __DIR__"yunv-jian/" + action;
}
int help(object me)
{
	write(HIC"\n玉女剑法："NOR"\n");
	write(@HELP

    古墓派开山祖师林朝英自创剑法，不但剑招凌厉，而且讲究丰
神脱俗、姿势娴雅，端的是美轮美奂、曼妙已极。

	学习要求：
		玉女心法15级
HELP
	);
	return 1;
}

