// jiangjun-zhang.c 裴将军诗杖法

inherit SKILL;

mapping *action = ({
([      "action":               
"$N手中$w向$n的$l连点三点，正是「裴」字起首三笔！",
	"damage":		100,
	"damage_type":  "挫伤"
]),
([      "action":               
"$N挥起$w，对准$n的$l虚点，自右上角至右下角弯曲而下，正是「如」字草书！",
	"damage":		120,
	"damage_type":  "挫伤"
]),
([      "action":               
"$N横过$w，写了个「猛」字，对着$n斜扫过去！",
	"damage":		140,
	"damage_type":  "挫伤"
]),
([      "action":               
"$N大喝一声，笔法一变写出个「将」字，$w一挺撞向$n$l！",
	"damage":		160,
	"damage_type":  "挫伤"
]),
([	"action":
"$N身形微转，$w向着$n的$l横扫过去，顺势带出个「龙」字！",
	"damage":		180,
	"damage_type":		"瘀伤",
]),
([	"action":
"$N高高跃起，手中$w划出个「壮」字，向着$n的$l撞了过来！",
	"damage":		200,
	"damage_type":		"挫伤",
]),
([	"action":
"$N怒喝一声，手中$w急舞正是个「腾」字，将$n$l罩于杖下！",
	"damage":	250,
	"damage_type":	"内伤",
]),
});

int valid_learn(object me)
{
	if(me->query_skill("xuantian-zhi",1)<20)
		return notify_fail("你的「玄天指法」不够娴熟。\n");
	if ((int)me->query_skill("kuihua-xinfa", 1) < 120)
		return notify_fail("你的葵花心法火候不够。\n");
	if(me->query("max_neili")<50)
		return notify_fail("你的内力修为不够。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff" )
                return notify_fail("你必须先找一根木杖或者是类似的武器，才能练杖法。\n");

	if((int)me->query("qi") <40)
                return notify_fail("你的体力不够练这门杖法，还是先休息休息吧。\n");
	me->receive_damage("qi",40);
        return 1;
}
 
