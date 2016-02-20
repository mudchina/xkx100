// bandage.c

#include <ansi.h>
inherit ITEM;
inherit F_EQUIP;
void create()
{
        set_name( HIW"手绢"NOR, ({ "shou juan", "piece"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "方");
                set("material", "cloth");
                set("long", "这是一方雪白的手绢。\n");               
                set("armor_type", "bandage");
                set("armor_prop/attack", -10);
                set("armor_prop/defense", -10);
                set("armor_prop/unarmed", -10);
        }
}

void init()
{
        add_action("do_bandage", "bandage");
        add_action("do_look", "look");
}

int wear() { return 0; }

int do_look(string arg)
{
        object me;
        me = this_player();
 
        if(!arg) return 0;
       
        if(id(arg)){
        if(query("blood_soaked") >= 2 && random(me->query("kar")) < 10 && !query("blooded"))
           {
            message_vision("$N正拿着张手绢仔细地端详着。\n", me);
            if(!query_temp("blooded")){            
                 tell_object(me, HIY "\n你突然发现这张手绢有点奇怪，被染过血的地方有了点变化！\n\n"NOR);
                 set_temp("blooded", 1);
                 return 1;
                 }
            else if(query_temp("blooded") < 3){
                 tell_object(me, HIY "\n这张手绢被染过血的地方开始出现了点变化！\n"NOR);
                 add_temp("blooded", 1);
                 return 1;
                 }
            else {                 
                 tell_object(me, HIY "\n你仔细研究了一下，才发现这是张地图，被血浸了后才慢慢现出图案来！\n\n"NOR);
                 set("blooded", 1);
                 delete_temp("blooded");
                 if (query("owner")==me->query("id"))
                   me->set_temp("li_meet",2);
                 set("long", "这是一张被血染红了的手绢，上面的图象有些奇怪，好象是张地图。\n");
                 return 1;
                }
            }
        else {
             write(query("long"));
             return 1;
             }
      }
        
}

int do_bandage(string arg)
{
        object ob;
        if( (int)query("blood_soaked") >= 2 )
                return notify_fail( name() + "已经被鲜血浸透，不能再用了。\n");

        if( query("equipped") )
                return notify_fail( name() + "已经裹在你的伤口上了，如果你要用来包扎别人，请你先把它除下来。\n");

        if( !arg ) ob = this_player();
        else {
                ob = present(arg, environment(this_player()));
                if( !ob || !userp(ob))
                        return notify_fail("你要替谁裹伤？\n");
        }

        if( this_player()->is_fighting()
        ||      ob->is_fighting() )
                return notify_fail("战斗中不能裹伤。\n");

        if( (int)ob->query("eff_qi") == (int)ob->query("max_qi") )
                return notify_fail( (ob==this_player()? "你" : ob->name())
                        + "并没有受到任何外伤。\n");

        if( ob->query_temp("armor/bandage") )
                return notify_fail( ob->name() + "身上的伤已经裹著其他东西了。\n");

        if( !move(ob) ) return 0;

        if( ob==this_player() )
                message_vision("$N用" + name() + "替自己裹伤。\n", this_player());
        else
                message_vision("$N用" + name() + "替$n裹伤。\n", this_player(), ob);
        ::wear();
        ob->apply_condition("bandaged", 40);
        add("blood_soaked", 1);
        
        return 1;
}

void remove(string euid)
{
        ::remove(euid);
        if( query("equipped") && environment() )
                environment()->apply_condition("bandaged", 0);
}