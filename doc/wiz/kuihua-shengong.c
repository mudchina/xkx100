// kuihua-shengong.c

#include <ansi.h>
inherit FORCE;

string *parry_msg = ({
"$n左一拨，右一拨，上一拨，下一拨，将$N的招数尽数拨开。这四下拨挡，周身竟无半分破绽。\n",
"$n右手大拇指和食指捏住一根绣花针，向上一举，挡住来势，$N的招式便使不下去。\n",
"$n不挡不闪，左手食指颤动，向$N的左目急刺，竟是两败俱伤的打法。\n",
"$n左拨右挡，兀自好整以暇的啧啧对$N连赞：“好功夫，好功夫！”\n",
"$n从怀中取出一块雪白的绸帕，轻轻抹了抹脸，简直便如是戏台上的花旦。$N一呆，竟停住了自己的招式。\n"
});

string  *msg = ({
"$N身形一变，如闪电般欺到$n身前，相距不过一尺，手中$w已经刺到$n的$l",
"但见红影闪处，$N手中的$w向$n的$l直戳而来，势如奔雷，避不可避",
"$N欺身而上，左手在$n的肩上一拍再横飞出去，而手中的$w却指向$n的$l",
"$N突然跃起丈余，$n一抬头，发现空中并无$N的身影，而一股寒气却从后袭来",
"$N左一拨，右一拨，上一拨，下一拨，将$n的招数尽数拨开，右手一转，刺向$n",
"蓦地里$N空手猱身而上，双手擒拿点拍，攻势凌厉之极，乘$n惊骇之际弹出$w刺向$n",
"$N身形飘忽，有如鬼魅，转了几转，移步向西，一剑刺向$n。出手之奇之快，直是匪夷所思",
"$N脚下一顿，站立片刻，忽向$n的左后方滑出丈余，跟着快速无伦的回到原处",
"$N潜运内力，忽进忽退，绕着$n身子乱转，手中$w所使剑招也如狂风骤雨一般，越来越快",
"突然$N手中$w向上一撩，就在$n微一分神之际直取$n的$l，势道劲急无伦"NOR,
"就在$n一呆之际，$N向右跃开两尺，右足刚著地，身子跟著弹起，刷刷两剑，向$n攻去",
"$N忽然化身为二，分出左右两个身影高速滑向$n，手中$w幻化不定，直刺$n的$l",
"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开",
"$N一声尖叫，飞身纵起，在半空中一转，快绝无比的飞落下来，手中$w破空直刺$n$l",
"$N忽然化身为二，分出上下两个身影高速滑向$n，手中$w变幻莫测，直刺$n的$l",
"$N的身形如鬼如魅，飘忽来去，直似轻烟，手中的$w却总是对着$n身子",
"$N一声冷笑，蓦地里疾冲上前，当真是动如脱兔，一瞬之间，与$n相距已不到一尺，两人的鼻子几乎要碰在一起",
"$N右手伸出，在$n手腕上迅速无比的一按，跟着手臂回转，又在$n手肘下一推",
"$N一剑挺刺，极尽都雅，神态之中，竟大有华山派女弟子所学‘玉女剑十九式’的风姿，只是带着三分阴森森的邪气",
"$N左手一圈，倒转$w，蓦地刺出，刷刷刷急攻三式，招招尽是指向$n的要害"
});

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "force" || usage =="parry"; 
}
mapping query_action(object me, object weapon)
{               
       return ([
          "action":msg[random(sizeof(msg))],
          "damage":(random(4)+1)*60,
          "damage_type": "刺伤",
          "dodge": random(30)+10,
          "force":(random(200)+60),
       ]);
}
string query_parry_msg()
{
        return parry_msg[random(sizeof(parry_msg))];
}
int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
               return notify_fail("你使用的武器不对。\n");
       if ((int)me->query_skill("kuihua-shengong", 1) < 180)
               return notify_fail("你还没有领会葵花神功的精髓，不能自行练习。\n");
       if ((int)me->query("qi") < 30)
               return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("你的内力不够了。\n");
       me->receive_damage("qi", 50);
       me->add("neili", -20);
       return 1;
}

int valid_learn(object me)
{
        if ((int)me->query_skill("kuihua-shengong", 1) < 180)
        return notify_fail("葵花神功只能通过研习《葵花宝典》来学习。\n"); 
}

string perform_action_file(string action)
{
        return __DIR__"kuihua-shengong/" + action;
}

string exert_function_file(string func)
{
       return __DIR__"kuihua-shengong/" + func;
}
