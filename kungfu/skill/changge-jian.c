// changge-jian.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit SKILL;
/* 武功类型，分knowledge、martial martial分force、dodge和skill */
string type() { return "martial"; }
string martialtype() { return "skill"; }

/* 攻击信息 */
mapping *action = ({
([	"action"     : "$N一声长叹，$w轻点一招"MAG"「醉拍春衫惜旧香」"NOR"向着$n的$l疾刺而去",
	"skill_name" : "醉拍春衫惜旧香",
	"lvl"        : 0,
]),
([      "action"     : "$N紧缩眉头，心中似有很深的怨气$w一闪而隐，一招" MAG"「天将离恨恼梳狂」"NOR"刺向$n的$l",
	"skill_name" : "天将离恨恼梳狂",
	"lvl"        : 10,
]),
([      "action"     : "$N仰天不语，脸上掠过一丝忧愁，$w暂缓，一招" HIG"「年年陌上生青草」"NOR"遥遥刺向$n的$l",
	"skill_name" : "年年陌上生青草",
	"lvl"        : 20,
]),
([      "action"     : "$N怔怔而望，若有所思，忽然变招，蓦然有骤风席卷，剑招凌烈撒向$n的$l，好一招"RED"「日日楼中到夕阳」"NOR,
	"skill_name" : "日日楼中到夕阳",
	"lvl"        : 30,
]),
([      "action"     : "$N衣袂飞舞，身形舒缓如舞，轻歌曼妙，一招" HIC"「云渺渺，水茫茫」"NOR"，$w划向$n的$l",
	"skill_name" : "云渺渺，水茫茫",
	"lvl"        : 40,
]),
([      "action"     : "$N微闭双目，一股落寞的神情布于脸上，剑意凝重，空气顿时压力大增一招"YEL"「征人归路许多长」"NOR"飞刺$n的$l",
	"skill_name" : "征人归路许多长",
	"lvl"        : 60,
]),
([      "action"     : "$N斜倚长剑，轻啸而歌却充满了枯涩的意味，$w自肋下翻刺而出一招"HIM"「相思本是无凭语」"NOR"刺向$n的$l",
	"skill_name" : "相思本是无凭语",
	"lvl"        : 80,
]),
([      "action"     : "$N缓缓摇头，双目中似有泪光闪动$w辉映着苍白的光芒若隐若现的闪现而出，一招"YEL"「莫向花笺费泪行」"NOR+"刺向$n的$l",
	"lvl"        : 100,
	"skill_name" : "莫向花笺费泪行",
]),
});

/* 招架信息 */
string *parry_msg = ({
	HIY"却见$n踏前一步，剑式斜指$P的右臂，想要使$P闪身而退。\n"NOR,
	HIY"$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来！\n"NOR,
});

/* 轻功信息 */
string *dodge_msg = ({
	HIC"$n一个"HIG"「江上弄春笛」"HIC"，平飞后跃，躲过了$N这一招。\n",
	HIC"$n一个"HIY"「大漠孤烟直」"HIC"，飞身纵起，身型曼妙，避开了$N的这一招。\n",
	HIC"$n一个"HIB"「海上生明"HIY"月"HIB"」"HIC"，身形恍惚，$N只觉眼前一花，招数落空。\n",
	HIC"$n手臂一转，顺势一侧身，一式"HIM"「长安市上酒家眠」"HIC"闪到一旁。\n",
	HIC"$n右手一挥，转身就走，马上又"HIG"「天涯涕泪一身遥」"HIC"，回身欺到$N身前。\n",
});

/* 可激发的武功类型 */
int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry" || usage == "dodge";
}

/* 可与互备的武功 */
int valid_combine(string combo) { return combo=="king-of-dragon"; }

/* 招数效力的条件，目前我们没限制 */
int valid_effect(object me, object weapon, string name, int skill) { }

/* 学习的条件。practice也要检测本函数，所以，在这里限制内功和内力就够了。 */
int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("king-of-dragon", 1) < 200 )
		return notify_fail("你的帝王神功不够精熟，没法练长歌剑法。\n");
	if( (int)me->query("max_neili") < 200 )
		return notify_fail("你的内力不够，没有办法练长歌剑法。\n");
	if( !(ob = me->query_temp("weapon")) || 
		(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	return 1;
}

/* 练习的条件 */
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 3 )
		return notify_fail("你内力或气不够，没有办法练习长歌剑法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
	write("你按着所学练了一遍长歌剑法。\n");
	return 1;
}

/* 学习的招数表现 */
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

/* 升级的信息及副作用 */
void skill_improved(object me)
{
	tell_object(me, HIR "你轻轻一弹剑锋，声如龙吟。\n" NOR );
	me->add("shen", 200);
}

/* 击中对方的副作用 */
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_temp("apply/armor") )
	{
		victim->receive_wound("qi", (damage_bonus - 20) / 2 );
		victim->apply_condition("xx_poison", 10 );
		return HIR "你听到「噗」地一声轻响，鲜血飞溅！\n" NOR;
	}
}

/* 被击中对方的副作用，目前主要用在内功上 factor= 加力 damage_bonus=臂力 */
mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;

	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	if ((int)random(ap/2)>dp && me->query("neili")>2000)
	{

		tell_object(me, HIY"你只觉得尽力袭体，急忙运起金钟罩神功，一股真气弥漫全身！\n"NOR);
		me->add("neili",-2*damage_bonus);
		return -damage_bonus;
	}
	return 0;
}

/* 激发成攻击武功的信息 */
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -30;
	int d_e2 = 30;
	int p_e1 = -30;
	int p_e2 = 30;
	int f_e1 = 150;
	int f_e2 = 230;
	int m_e1 = 250;
	int m_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("changge-jian", 1);
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

/* 激发成招架武功的信息 */
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
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
int practice_bonus() { return 15; }

/* 对师傅传授产生误解的比率。random(success()) == 0的时候误解。暂时不用。
数值越大越不容易误解。误解引起倒退或停滞，仅体现在learn & teach */
int success() { return 10; } 

/* 威力参数，参照门派参数，限制范围1到1.5。严禁超标！目前仅用于轻功。 */
int power_point() { return 1; }

/* 绝招文件目录 */
string perform_action_file(string action)
{
	return __DIR__"changge-jian/" + action;
}

/* 内功应用文件目录 */
string exert_function_file(string func)
{
	return __DIR__"changge-jian/" + func;
}

/* 帮助信息 */
int help(object me)
{
	write(HIC"\n长歌剑法："NOR"\n");
	write(@HELP

    长歌剑法不对玩家开放。
    长歌剑法可激发成剑法、招架和轻功。用于NPC制作。
    
HELP
	);
	return 1;
}
