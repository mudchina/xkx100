// shulin1.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","山谷");
       set("long", @LONG
你走进山谷，这里林木茂密，有如仙境。只见两山之间流出一条小溪来，
清澈的溪水从你脚边静静地淌过。口渴的你正好可以饮(drink)个饱。
LONG);
        set("resource/water", 1);
        set("exits", ([
                "southeast" : __DIR__"shulin",
                "north" : "/d/gaochang/road",
        ]));
        set("outdoors", "hasake");
        set("no_quest",1);
        setup();
}


int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"用手捧起清水喝了几口。\n", environment(me), ({me}));
            write("你只觉溪水微带甜味，甚是清凉可口。\n");
            }
        else write("你喝不下了。\n");
        return 1;
}
void init()
{
/*        object ob = this_player();        
        if(interactive(ob) &&  ob->query_temp("li_meet") == 2) {
             ob->add_temp("li_meet", 1);
             new(__DIR__"obj/shoujuan2")->move(ob);
             write("
你发现树枝上有一方李文秀留下的白手绢，原来在你晕倒后是她救了你出来。
你左右看了看，发现李文秀早就离开了，那这里。。。这里莫非就是。。。？\n");
        }        
*/        add_action("do_drink", "drink");
}