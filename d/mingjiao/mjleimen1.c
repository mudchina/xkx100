// Room: /d/mingjiao/mjleimen1.c
// Jan.5 1997 by Venus

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "雷字门口");
	set("long", @LONG
前面就是明教的“雷字门”了，这里是明教中西域弟子修炼的地方。
西域风俗大异中土，他们的生活习惯以及使用物品也与中土迥异。
LONG );
	set("exits", ([
		"enter" : __DIR__"sushe",
		"northeast" : __DIR__"mjleimen",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -51110);
	set("coor/y", 490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}