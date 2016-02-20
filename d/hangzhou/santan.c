// santan.c
// Date: Nov.1997 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "三潭印月");
        set("long", @LONG
这里是西湖小瀛洲的“我心相应”亭，小瀛洲人称“湖中有岛，岛
中有湖”。亭前有联曰：“客中客入画中画  楼外楼看山外山”。岛后
三塔为东坡狩杭时所建。“塔影亭亭引碧流”、“玲珑塔底月轮悬”，
遂使“三潭印月”位列西湖十景。
    元代三塔被毁，大明万历重建时已不在原处，致成今时“天上月一
轮，湖中影成三”之景。亭边泊着小舟(zhou)是送游客去苏堤。
LONG);
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4130);
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
	message_vision("梢公一见有人上船，轻摇木桨，小舟西行。\n", ob);
	ob ->move(__DIR__"xihu") ;
	tell_object(ob, HIG "你在湖面穿行，轻风徐来，满面生暖。\n" NOR ) ;
	call_out("tostyy", 10 , ob );
	return 1 ;
}
void tostyy(object ob )
{
	tell_object(ob , "小舟轻轻靠上苏堤。你走下船来。\n" ) ;
	ob->move (__DIR__"suti6") ;
}
