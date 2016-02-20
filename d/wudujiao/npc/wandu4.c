// wandu4.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("九尾蝎",({"xie zi"}));
	set("race", "昆虫");
	set("subrace", "爬虫");
        set("long", "一条一丈来长，有九只尾蛰的大蝎子。\n");
        set("age", 10000);
        set("attitude", "peaceful");

        set("max_jing", 1500);
        set("max_qi", 1500);

        set("str", 40);
        set("con", 50);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_skill("unarmed",180);
        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("force",180);
        set("combat_exp", 500000);
        set_weight(500000);

        setup();
}
void init()
{
        object me,ob;
        add_action("do_train", "xun");
        if (interactive(me = this_player()) && 
            (string)me->query("family/family_name") != "五毒教")
        {
               remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
        }
        ::init();
}

int hit_ob(object me, object ob, int damage)
{
        if ((string)ob->query("family/family_name") != "五毒教") {
                ob->apply_condition("xiezi_poison", 20
              +(int)ob->query_condition("xiezi_poison") );
              tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
        }
}

#include "wandu.h";
