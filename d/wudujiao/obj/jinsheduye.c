// jinsheduye.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat","eat");
}

void create()
{
               set_name("金蛇毒液", ({"jinshe duye" ,"duye"}));

                set("unit", "瓶");
                set("long", "这是一瓶剧毒的金蛇毒液。\n");
                set("value", 100);
//            set("no_drop", "这样东西不能离开你。\n");
              set_weight(100);


        setup();
}

int do_eat(string arg)
{
    object me = this_player();
    object ob = this_object();
    if (!id(arg))
    return 0;
    tell_object(me,  "你想死啊，用suicide比较快一点。\n" );
    return 1;
}
