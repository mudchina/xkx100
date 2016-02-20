// Room: /d/lingxiao/fentianya.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void init();
void create()
{
	set("short", "分天崖");
	set("long", @LONG 
这里就是凌霄城的天险—分天崖。往外望去，只见万丈深谷上，横
着一座又窄又滑的冰梯，雪花飘落，更是滑溜，在强劲的罡风中，给人
一种摇摇欲坠的感觉。
LONG);
	set("outdoors", "lingxiao");
	set("exits", ([
		"southdown" : __DIR__"sroad6",
		"up"        : __DIR__"bingti",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8940);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}

