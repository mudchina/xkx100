// zhulou.c
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_shou","shouchong");
        add_action("do_fang","fangchong");
}

void create()
{
               set_name("竹篓", ({"zhu lou" ,"zl"}));
              set_max_encumbrance(30000);
                set("unit", "个");
                set("long", "这是一个小口大肚的竹篓。\n");
                set("value", 100);
//            set("no_drop", "这样东西不能离开你。\n");
              set_weight(100);
              set("no_sell",1);
                setup();
}

int do_shou(string arg)
{
    object me,ob1,ob;
    string who,what;
    me = this_player();
//  ob1= this_object();
    if( !arg
        ||      sscanf(arg, "%s in %s", who, what)!=2)
         return notify_fail("命令格式: shouchong <毒虫> in <物品>。\n");
    ob1= present(what,me);
    ob = present(who,environment(me));
    if (!ob )
         return notify_fail("你要收什么？\n");
    if (!ob1 )
         return notify_fail("你要将虫收到那里？\n");
    if(me->query("id")!=(ob->query("host_id"))||ob->query("age")<100)
         return notify_fail(ob->query("name")+"连理都不理你！\n");
    message_vision("$N打开竹篓，对着"+ob->query("name")+"轻轻吹了一声口哨。\n",me);
    message_vision("只见"+ob->query("name")+ "身子逐渐缩小，化做一只几寸长的小虫，钻进了$N的竹篓里。\n",me);
     ob->move(ob1);
     return 1;
}
int do_fang(string arg)
{
    object me,ob1,ob;
    string who,what;
    me = this_player();
    me = this_player();
//  ob1= this_object();
    if( !arg
        ||      sscanf(arg, "%s from %s", who, what)!=2)
         return notify_fail("命令格式: fangchong <毒虫> from <物品>。\n");
    ob1 = present(what,me);
    if (!ob1)
         return notify_fail("你要从那里放毒虫？\n");
    ob = present(who,ob1);
    if (!ob )
         return notify_fail("你要放什么？\n");
    if(me->query("id")!=(ob->query("host_id"))||ob->query("age")<100)
         return notify_fail(ob->query("name")+"连理都不理你！\n");
    tell_object(me,  "你悄悄打开竹篓，将里面的"+ob->query("name")+"放了出来。\n");

    message_vision("忽然，一只"+ob->query("name")+"不知从什么地方窜了出来。\n",me);
     ob->move(environment(me));
     return 1;
}
