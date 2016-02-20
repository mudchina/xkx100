// yanfly.c 燕双飞
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

/* 轻功信息 */
string *dodge_msg = ({
	"$n一个"HIW"「比翼双飞」"NOR"，随着$N的攻势飘起，从容躲过这一招。\n",
	"$n使出一招"HIC"「巧燕穿云」"NOR"，猛然纵起丈余，结果$N扑了个空。\n",
	"$n身形一摇，幻出几个人影，一招"HIW"「望穿秋水」"NOR"躲过了$N的攻势。\n",
	"$n一招"MAG"「飞鸟投林」"NOR"纵身跃起，倏忽已落至$N身后。\n",
	"$n左一摇，右一晃，一招"HIM"「紫燕呢喃」"NOR"已轻松闪过。\n",
});

/* 可激发的武功类型 */
int valid_enable(string usage) { return usage=="dodge" || usage=="move"; }

/* 学习的条件。practice也要检测本函数，所以，在这里限制内功和内力就够了。 */
int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("king-of-dragon", 1) < 20 )
		return notify_fail("你的帝王神功不够精熟，没法练燕双飞。\n");
	if( (int)me->query("max_neili") < 10 )
		return notify_fail("你的内力不够，没有办法练燕双飞。\n");
	return 1;
}

/* 练习的条件 */
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 )
		return notify_fail("你的体力太差了，不能练燕双飞。\n");
	if (me->query_skill("yanfly", 1) < 30)
		me->receive_damage("qi", 10);

	me->receive_damage("qi", 20);
	return 1;
}

/* 激发成轻功的打斗信息 */
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

/* 武功难度系数 = 100 / (learn_bonus+parctice_bonus+10) 在skill.c命令中体现 */
/* 每点潜能所能学到的本技能点数 = random(query_int()/2+query("int")/2+bonus) */
/* 限制范围 0 - 30 */
int learn_bonus() { return 10; }

/* 每次练习获得技能点数 = (random(基本武功*基本武功/(skill+1)))/5+bonus */
/* 限制范围 0 - 30 */
int practice_bonus() { return 5; }

/* 对师傅传授产生误解的比率。random(success()) == 0的时候误解。暂时不用。
数值越大越不容易误解。误解引起倒退或停滞，仅体现在learn & teach */
int success() { return 10; }

/* 威力参数，参照门派参数，限制范围1到1.5。严禁超标！目前仅用于轻功。 */
int power_point(object me) { return 1.5; }

/* 绝招文件目录 */
string perform_action_file(string action)
{
        return __DIR__"yanfly/" + action;
}

/* 帮助信息 */
int help(object me)
{
	write(HIC"\n燕双飞："NOR"\n");
	write(@HELP

	学习要求：
		帝王神功20级
		内力修为10
HELP
	);
	return 1;
}

