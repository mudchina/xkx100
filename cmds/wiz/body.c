// bigu.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
        int fw;

        me = this_player();

        if( !me->query_condition("f_condi") )
        {
                write(HIY"你口中念念有词，那咦咪哞嘻...\n"NOR);
                tell_object(me,"你只觉神清气爽，哈哈！\n");

                fw = (int)me->max_food_capacity();
                me->set("food", fw);
                fw = (int)me->max_water_capacity();
                me->set("water", fw);
                me->set("jing",me->query("max_jing"));
                me->set("eff_jing",me->query("max_jing"));
                me->set("qi",me->query("max_qi"));
                me->set("eff_qi",me->query("max_qi"));
                me->set("jingli",me->query("max_jingli"));
                me->set("neili",me->query("max_neili"));
                me->set("tili",me->query("max_tili"));
          //      me->set("potential",me->query("learned_points")+ 75);

                me->apply_condition("f_condi", 5);
        }
        else
        {
                tell_object(me,"Ou。。你打了个饱嗝。。。Ou...Ou...\n");

                fw = (int)me->max_food_capacity();
                me->set("food",fw);
                fw = (int)me->max_water_capacity();
                me->set("water",fw);
                me->set("water", fw);
                me->set("jing",me->query("max_jing"));
                me->set("eff_jing",me->query("max_jing"));
                me->set("qi",me->query("max_qi"));
                me->set("eff_qi",me->query("max_qi"));
                me->set("jingli",me->query("max_jingli"));
                me->set("neili",me->query("max_neili"));
                me->set("tili",me->query("max_tili"));
          //      me->set("potential",me->query("learned_points")+ 75);
        }
        return 1;
}

