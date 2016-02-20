// Room: /d/songshan/danfang.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "丹房");
	set("long", @LONG
左冷禅既是一代武学宗师，刀圭之术亦甚是了得。他在对药理也十
分精通。丹房内放置着数百只白瓷瓶子装着，贴上标签，分门别类地放
在四周的药架上。
LONG);
	set("exits", ([
		"east" : __DIR__"houting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 930);
	set("coor/z", 90);
	setup(); 
	replace_program(ROOM);
}
