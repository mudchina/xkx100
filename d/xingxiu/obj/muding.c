#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"神木王鼎"NOR,({ "shenmu wangding", "wangding", "shenmu" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "一只雕琢而成的暗黄色小木鼎, 木理之间隐隐泛出红丝。鼎侧有五个铜钱大的圆孔，木鼎齐颈出有一道细缝，似乎上下分为两截。\n");
                set("value", 5);
                set("muding/remaining", 0);                
        }
}

void init()
{
    add_action("do_suck", "suck");
}

int do_suck(string arg)
{
        object me = this_player();

        if ( arg != "blood" || !living(this_player()))
        return notify_fail("你要吸什么？\n");

        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成, 不能运功练毒。\n");
        if ( me->is_fighting())
        return notify_fail("你在战斗中不能运功练毒。\n");

        if(query("muding/remaining") < 1)
                return notify_fail("木鼎中没有血水了。\n");

        message_vision("$N伸掌将血液接住，盘膝运功，将血液吸入掌内。\n", me);
           me->receive_damage("jing", 10);
           me->receive_damage("jingli", 10);
           me->receive_damage("qi", 15);
           me->receive_damage("neili", 3);

        add("muding/remaining", -1);
        if ((int)me->query_skill("poison", 1) <= 30){
              me->apply_condition("xx_poison", 5);
              return 1;
              }
        if ((int)me->query_skill("poison", 1) > 50 ) return 1;

        if(random(10) > 6){
          switch(random(3)) {
            case 0:
                  me->improve_skill("poison", (int)(me->query("int") / 2));
                  write (RED"你只觉掌中微微一凉，一股阴气顺着脉络侵入脑髓。\n"NOR"你对基本毒技的领会又加深了一些！\n");
                  break;
            case 1:
                  me->improve_skill("chousui-zhang", (int)(me->query("int") / 2));
                  write (RED"你只觉掌中微微一痒，一股毒气自掌沿手臂上升。\n"NOR "你对抽髓掌的领会又加深了一些！\n");
                  break;
            case 2:
                  me->improve_skill("huagong-dafa", (int)(me->query("int") / 2));
                  write (RED"你只觉掌中微微一痒，一股阴毒之气自掌沿手臂上升，直达丹田。\n"NOR "你对化功大法的领会又加深了一些！\n");
                  break;
                  }
            }
         return 1;
}
