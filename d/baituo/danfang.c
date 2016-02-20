// Room: /d/baituo/danfang.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "丹房");
	set("long", @LONG
欧阳锋既为“西毒”，他在对药理也当真十分精通。这丹房内上千
种医药、毒药全用白瓷瓶子装着，贴上标签，分门别类地放在四周的药
架上，令人一目了然，越也增加了一丝恐惧之心。
LONG);
	set("exits", ([
	      "east" : __DIR__"tuitang",
	]));
	set("objects", ([
		__DIR__"obj/grass" : 1,
	]));
	set("coor/x", -50020);
	set("coor/y", 20055);
	set("coor/z", 30);
	setup(); 
	replace_program(ROOM);
}
