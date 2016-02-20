// Jay 3/17/96

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;

void create()
{
        set_name("柔丝索", ({"rousi suo", "silk", "suo"}));
        set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
        else {
                set("unit", "摞");
                set("rigidity", 1);
                set("unique", 1);
                set("long", "这是一摞微细透明, 几非肉眼所能察见的丝索。\n");
                set("value", 10000);
                set("material", "leather");
                set("wield_msg", "$N轻轻抽出一摞$n套在手上。\n");
                set("unwield_msg", "$N将手中的$n卷成一团，放入袖中。\n");
        }
        init_whip(10);
        setup();
}

void init()
{
        add_action("do_tao","tao");
}

int do_tao(object me, object target)
{
        string msg;

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("你只能在战斗中的偷袭对手用。\n");

        if (me->is_busy()) 
                return notify_fail("你现在正忙着呢。\n");

        if (me->query_skill_prepared("strike") != "chousui-zhang" ||
            me->query_skill_mapped("strike") != "chousui-zhang" ||
            me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("你必须先将化功大法功和抽髓掌法相互配合，才能使用柔丝索！。\n"); 
       
        if( (int)me->query_skill("huagong-dafa",1) < 80 )
                return notify_fail("你的化功大法功力不够，使用不了柔丝索！\n");
        if( (int)me->query_skill("chousui-zhang",1) < 80 )
                return notify_fail("你的抽髓掌功力不够，使用不了柔丝索！\n");

        if(me->query("combat_exp") < (int)target->query("combat_exp")/2 )
                return notify_fail("你想偷袭自己根本打不过的人？找死啊？\n");
 

        tell_object(me, HIW "\n你悄悄放开柔丝索，催动内力毫不起眼地一摆。\n\n" NOR);
                 

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
            random(10) > 5) 
               {
                msg = HIR"$n忽然动作一顿，竟然象被人绑住了一样！\n" NOR;
                tell_object(target, HIB "\n你身子突然一紧，才发现自己不知不觉间被人用东西套住了！\n\n" NOR);
                target->start_busy(4);
                } 
          else {
                me->start_busy(2);
                msg = HIY"忽然阳光一闪，正好照见$N抛出了什么东西，结果被$n机灵地躲了开去。\n" NOR;
                tell_object(me, HIB "\n你突然觉得阳光强了很多，糟糕！自己的企图被发现了！\n\n" NOR);
                tell_object(target, HIB "\n你突然看见了一条银白色的东西在阳光下一闪，马上跃了开去！\n\n" NOR);
                }

        message_vision(msg, me, target);
        me->add("neili", -50);
        me->add("shen", -(random(200)));
        return 1;
}