// suti6.c
// Date: Nov.1997 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "苏堤");
        set("long", @LONG
秋月之夜，月下观湖，唯见满湖银波粼粼，阵阵微风，风中桂子飘
香，令人为之心醉。堤边泊着小舟(zhou)是送游客去三潭映月的。往西
边是去花港，东面可见三潭映月遥立湖中，北边是锁澜桥，南面映波桥。
LONG);
        set("exits", ([
            "north"     : __DIR__"suti5",
            "south"     : __DIR__"suti7",
            "west"      : __DIR__"huagang",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4110);
	set("coor/y", -1440);
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
	if( !arg || arg !="zhou" ) 
	{
		tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
		return 1 ;
	}
	ob = this_player () ;
	message_vision("梢公一见有人上船，轻摇木桨，小舟东行。\n", ob);
	ob ->move(__DIR__"xihu") ;
	tell_object(ob, HIG "你在湖面穿行，轻风徐来，满面生暖。\n" NOR ) ;
	call_out("tostyy", 10 , ob );
	return 1 ;
}
void tostyy(object ob )
{
	tell_object(ob , "小舟轻轻靠上湖中小瀛洲。你走下船来。\n" ) ;
	ob->move (__DIR__"santan") ;
}
