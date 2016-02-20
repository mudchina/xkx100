// Room:  /d/luoyang/baiyuan.c
// Last modified by winder 2002.11.11

#include <ansi.h>
inherit  ROOM;

void  create  ()
{
	set("short",  "白园");
	set("long",  @LONG
白园或称白冢，在东香山北端琵琶峰上。墓前石碑刻“唐少傅白公
墓”六字。白居易晚年寓居香山，自号“香山居士”。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"westdown" : __DIR__"longmen",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -45);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

