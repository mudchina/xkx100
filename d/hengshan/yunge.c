// Room: /d/hengshan/yunge.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "云阁卧波");
	set("long", @LONG
过完栈道，就到云阁虹桥。前往恒山主峰见性峰，都要在这里跨过
唐峪河。拱桥卧波，水天亮丽，倍觉胸襟舒畅。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"east"      : __DIR__"daziling",
		"northdown" : __DIR__"zhandao",
	]));
	set("objects", ([
		CLASS_D("hengshan")+"/zhi" : 1,
	]));
	set("outdoors", "hengshan");
//	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3140);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

