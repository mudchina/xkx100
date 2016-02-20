// Room: /d/mingjiao/mjtianmen1.c
// Jan.5 1997 by Venus

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "天字门口");
	set("long", @LONG
前面就是明教的“天字门”了，这里是明教中男弟子修炼的地方，
从门口看进去，汗衫扬臭，木桌流酒。此处不允女人随意进入。
LONG );
	set("exits", ([
		"enter" : __DIR__"nanshe",
		"southeast" : __DIR__"mjtianmen",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -51110);
	set("coor/y", 710);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	me = this_player();
	if ((me->query("gender")!="男性") && (dir=="enter"))
		return notify_fail("请你自重，以免不测！\n");
	else  return 1;
}