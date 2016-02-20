// wangyun.c 望云台

inherit ROOM;

#include <ansi.h>
int do_take(string arg);

void create()
{
        set("short", "望云台");
        set("long", @LONG
这里就是侠客岛最高的 "望云台" 。在这里你可以远望大海，
运气好的时候还能看见一大奇景-- "云海" 。在石缝之间长着一颗
松树，俗称 "可怜松" 。在松树周围还顽强的生长着几颗小草(cao)。
LONG    );
        set("exits", ([
                "northdown" : __DIR__"road8",
        ]));
        set("outdoors", "xiakedao" );
        set("item_desc",([
            "cao" : "几珠碧绿的小草，你不禁想拿(take)起来。\n"
        ]) );
        set("no_clean_up", 0);
        set("caocount", 1);
	set("coor/x", -3110);
	set("coor/y", -22150);
	set("coor/z", 40);
	setup();
}

void init()
{
        add_action("do_take","take");
}
int do_take(string arg)
{
        object me=this_player();
        object obn;
        int n;
        n = this_player()->query_skill("dodge",1);
        if( !arg || arg != "cao" )
        {
             write("你要拿什么呀!\n");
             return 1;
        }
message_vision("$N在悬崖前站定，深呼一口气，突然跃起。\n", this_player());
        if(n >=80)
        {
             if(query("caocount") > 0)
             {
message_vision("只见$N的身子在空中打了几个盘旋，身子轻飘飘落回，手中多了一物。\n", this_player());
                 obn = new("/clone/medicine/vegetable/fuxincao");
                 obn->move(me);
                 add("caocount",-1);
             }
             else
message_vision("$N定睛一看，发现草早被人拿走了。\n", this_player());
        }
        else
        {
             me->receive_damage("qi", 50);
             me->receive_wound("qi", 50);
             message_vision(HIR" 只见$N的身子在空中打了几个盘旋，呀! 不好!!!!\n"NOR, this_player());
             me->move(__DIR__"gudi");
             tell_object(me,HIR"你从悬崖上摔了下来，浑身疼痛，还受了几处伤。" NOR);
message("vision", HIR "只见" + me->query("name") + "你从悬崖上摔了下来，
躺在地上，半天也不能动。\n" NOR, environment(me), me);
        }
        return 1;
}
