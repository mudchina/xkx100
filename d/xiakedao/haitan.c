// haitan.c
#include <ansi.h>

inherit ROOM;

void home( object ob ) ;

void create()
{
    set("short", "海滩");
    set("long", @LONG
这里就是侠客岛了。北边是一望无际的大海；往南则是一片树
林。岛上的空气似乎非常新鲜，咸湿的海风中带着一股花香，这是
好大的一片沙滩，东首石崖下停着四十多艘大小的船只(boat)。
LONG );

    set("item_desc", ([
        "boat" : "这是侠客岛对外联系的大船。岛上的客人或弟子只要\n"
                  "上船(enter)就可以回中原。\n",
    ]));
    set("exits",([
        "south" :__DIR__"lin1",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "xiakedao");
	set("coor/x", -3000);
	set("coor/y", -20000);
	set("coor/z", 0);
	setup();
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="boat" )
       {
         tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
    message_vision("船夫升起帆，船就向北方航行。\n", ob);
    ob ->move("/d/xiakedao/dahai") ;
    tell_object(ob, BLU "你在海上航行了三天三夜.......\n" NOR ) ;
    call_out("home", 10 , ob );
    return 1 ;
}
void home( object ob )
{
    tell_object(ob , "大船终于抵达了南海岸边。你走下船来。\n" ) ;
    ob->move (__DIR__"haigang") ;
}