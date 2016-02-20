// xianglong-zhang.c 降龙十八掌
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action" : "$N双掌平平提到胸前，神色沉重的缓缓施出"+(order[random(13)])+"「亢龙有悔」"NOR"推向$n的$l",
]),
([	"action" : "$N突然身形飞起，双掌居高临下一招"+(order[random(13)])+"「飞龙在天」"NOR"拍向$n的$l",
]),
([	"action" : "$N右掌一招"+(order[random(13)])+"「见龙在田」"NOR"，迅捷无比地劈向$n的$l",
]),
([	"action" : "$N双掌施出一招"+(order[random(13)])+"「鸿渐于陆」"NOR"，隐隐带着风声拍向$n的$l",
]),
([	"action" : "$N左掌聚成拳状，右掌一招"+(order[random(13)])+"「潜龙勿用」"NOR"缓缓推向$n的$l",
]),
([	"action" : "$N施出一招"+(order[random(13)])+"「利涉大川」"NOR"，右掌插腰，左掌劈向$n的$l",
]),
([	"action" : "$N使出"+(order[random(13)])+"「突如其来」"NOR"，右掌从不可能的角度向$n的$l推出",
]),
([	"action" : "$N大吼一声，双掌使出"+(order[random(13)])+"「震惊百里」"NOR"，不顾一切般击向$n",
]),
([	"action" : "$N使出"+(order[random(13)])+"「或跃在渊」"NOR"，向$n的$l连拍数掌",
]),
([	"action" : "$N身形滑动，双掌使一招"+(order[random(13)])+"「双龙取水」"NOR"一前一后按向$n的$l",
]),
([	"action" : "$N使出"+(order[random(13)])+"「鱼跃于渊」"NOR"，身形飞起，双掌并在一起向$n的$l劈下",
]),
([	"action" : "$N双掌立起，使出"+(order[random(13)])+"「时乘六龙」"NOR"向$n连砍六下",
]),
([	"action" : "$N使出"+(order[random(13)])+"「密云不雨」"NOR"，左掌封住$n的退路，右掌斜斜地劈向$l",
]),
([	"action" : "$N使出"+(order[random(13)])+"「损则有孚」"NOR"，双掌软绵绵地拍向$n的$l",
]),
([	"action" : "$N脚下一转，突然欺到$n身前，一招"+(order[random(13)])+"「龙战于野」"NOR"拍向$n的$l",
]),
([	"action" : "$N门户大开，一招"+(order[random(13)])+"「履霜冰至」"NOR"向$n的$l劈去",
]),
([	"action" : "$N使出"+(order[random(13)])+"「羝羊触蕃」"NOR"，双掌由下往上击向$n的$l",
]),
([	"action" : "$N左掌护胸，右掌使一招"+(order[random(13)])+"「神龙摆尾」"NOR"上下晃动着击向$n的$l",
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

mapping sub_skills = ([
        "kanglong-youhui"  : 150,        // 1
        "feilong-zaitian"  : 150,        // 2
        "jianlong-zaitian" : 150,        // 3
        "hongjian-yulu"    : 150,        // 4
        "qianlong-wuyong"  : 150,        // 5
        "lishe-dachuan"    : 150,        // 6
        "turu-qilai"       : 150,        // 7
        "zhenjing-baili"   : 150,        // 8
        "huoyue-zaiyuan"   : 150,        // 9
        "shuanglong-qushui": 150,        // 10
        "yuyue-yuyuan"     : 150,        // 11
        "shicheng-liulong" : 150,        // 12
        "miyun-buyu"       : 150,        // 13
        "sunze-youfu"      : 150,        // 14
        "longzhan-yuye"    : 150,        // 15
        "lvshuang-bingzhi" : 150,        // 16
        "diyang-chufan"    : 150,        // 17
        "shenlong-baiwei"  : 150,        // 18
]);
int get_finish(object me)
{
        if (me->query("gender") == "无性")
        {
                tell_object(me, "你演练完毕，只觉体内真气阴阳不调，运功之"
                                "下几欲昏厥。\n");
                return 0;
        }

        if (me->query("str") < 25)
        {
                tell_object(me, "你演练完毕，只觉手臂又酸又软，痛得几乎抬"
                                "不起来。\n");
                return 0;
        }

        if (me->query("con") < 20)
        {
                tell_object(me, "你演练完毕，就觉得眼前金星乱冒，太阳穴突"
                                "突的跳。\n");
                return 0;
        }

        if ((int)me->query_skill("force") < 300)
        {
                tell_object(me, "你演练完毕，几乎虚脱，看来自身内功水平还"
                                "有待提高。\n");
                return 0;
        }

        if ((int)me->query("max_neili") < 3000)
        {
                tell_object(me, "你演练完毕，丹田提不起半点力来，看来应该"
                                "继续锻炼内力。\n");
                return 0;
        }

        if (random(30) <= 28 && !wizardp(me))
        {
                tell_object(me, "你对降龙十八掌的奥妙颇有领悟，或许多演练几次"
                                "就能融会贯通。\n");
                return 0;
        }

        tell_object(me, HIY "你一气呵成，将十八掌从头到尾演练了一变，心中"
                        "顿悟，通\n晓了降龙十八掌的奥妙精髓，融会贯通了掌"
                        "法的精微之处，\n再也非拆开使用那么那么简单。\n" NOR);
        me->set("can_use/xianglong-zhang",1);
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}
int get_ready()
{
				return 1;	
}
void skill_improved(object me)
{
        int i;
        string *sub_skillnames;

        sub_skillnames = keys(sub_skills);
        for (i = 0; i < sizeof(sub_skillnames); i++)
                me->delete_skill(sub_skillnames[i]);
}
int valid_learn(object me)
{
    if (!me->query("can_use/xianglong-zhang"))
    		return notify_fail("你未领悟到降龙十八掌精髓，不会用降龙十八掌。\n");

		if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
				return notify_fail("练降龙十八掌必须空手。\n");

		if ((int)me->query("max_neili") < 3000)
				return notify_fail("你的内力太弱，无法练降龙十八掌。\n");

		if ((int)me->query("str") < 25)
				return notify_fail("你的先天膂力孱弱，难以修炼降龙十八掌。\n");

		if ((int)me->query("con") < 20)
				return notify_fail("你的先天根骨孱弱，难以修炼降龙十八掌。\n");

		if ((int)me->query_skill("strike", 1) < 180)
				return notify_fail("你的基本掌法火候不够，难以修炼降龙十八掌。\n");

		if ((int)me->query_skill("strike", 1) < (int)me->query_skill("xianglong-zhang", 1))
				return notify_fail("你的基本掌法水平有限，无法领会更高深的降龙十八掌。\n");

	return 1;
}

int practice_skill(object me)
{
	if (!valid_learn(me)) return 0;
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练降龙十八掌。\n");
	me->receive_damage("qi", 100);
	me->add("neili", -40);
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
	int d_e1 = -60;
	int d_e2 = -40;
	int p_e1 = -20;
	int p_e2 = 10;
	int f_e1 = 520;
	int f_e2 = 640;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xianglong-zhang", 1);
	seq = random(ttl);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("xianglong-zhang", 1);

        if (damage_bonus < 100 || lvl < 150) return 0;

        if (damage_bonus / 4 > victim->query_con())
        {
		if (damage_bonus>200)
			victim->receive_wound("qi", (damage_bonus - 200) / 2 );
		else 
			victim->receive_wound("qi", (damage_bonus - 100) / 2 );

                return random(2) ? HIR "只听$n" HIR "前胸「咔嚓」一声脆响，竟像是"
                                   "肋骨断折的声音。\n" NOR:

                                   HIR "$n" HIR "一声惨叫，胸前「咔嚓咔嚓」几声脆"
                                   "响，口中鲜血狂喷。\n" NOR;
        }
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) 
{ 
	if (me->query_skill("huntian-qigong",1) >= 10)	return 0.8; 
	else return 1.0;
}

string perform_action_file(string action)
{
	return __DIR__"xianglong-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n降龙十八掌："NOR"\n");
	write(@HELP

    降龙十八掌是丐帮镇帮之宝，是天下最刚猛的武功。

	学习要求：
		自行演练，将十八路掌法合而为一
		内力3000
		先天臂力25
		先天根骨20
		基本掌法180
		基本掌法不低于降龙掌
HELP
	);
	return 1;
}

