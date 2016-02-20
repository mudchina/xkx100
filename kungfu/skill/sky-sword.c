// 这是玩家自创武功程序。
// winder
// 风儿
// 桃花岛第三代弟子
// 20000000
// 男性
// sword
// 天剑





inherit SKILL;

/////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
	"action" :"$N腾空跃起，一招“飞天”，手中$w冲着$n$l就是一剑",
	"damage" :50,
	"dodge" :20,
	"parry" :20,
	"damage_type": "刺伤",
	"skill_name" : "飞天"
]),
// ZHAOSHI :1

([
	"action" :"$N手腕一横，一招“行天”，手中$w如活物扫向$n的$l",
	"damage" :80,
	"dodge" :10,
	"parry" :20,
	"damage_type": "刺伤",
	"skill_name" : "行天"
]),
// ZHAOSHI :2

([
	"action" :"$N脚尖一点，一招“冲天”，手中$w自上而下向$n的$l劈去",
	"damage" :100,
	"dodge" :10,
	"parry" :10,
	"damage_type": "刺伤",
	"skill_name" : "冲天"
]),
// ZHAOSHI :3

([
	"action" :"$N左手剑指一划，一招“回天”，手中$w回转，自下而上向$n的$l撩去",
	"damage" :130,
	"dodge" :5,
	"parry" :10,
	"damage_type": "刺伤",
	"skill_name" : "回天"
]),
});
// ZHAOSHI :4
int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"天剑"+"。\n");
	return 1;
}
int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
int effective_level()
{
	return 30;
}
int practice_skill(object me)
{
	object weapon; 
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");	
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 40 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
	return 1;
} 
string *parry_msg = ({
	"$n使出一招虚招，手中$v虚点一招，突然回招换式，护住$n的全身。\n",
});
string *unarmed_parry_msg = ({ "$n一招反攻，用手中的$v荡开了$N的招式。\n", });
string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus()
{
	return -150;
}
int practice_bonus()
{
	return -150;
}
int black_white_ness()
{
	return 30;
}
string perform_action_file(string action)
{
	return CLASS_D("player") + "/"+"sword"+"/" + action;
}
