//Edited by fandog, 02/15/2000
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "小屋");
	set("long", @LONG
这是乡下农民住的小屋。屋里坐着个老者，背向窗子，瞧不见他的
面容。
LONG
	);
	set("exits", ([ 
          "west"  : __DIR__"taihuiguan",
          "south" : __DIR__"shangang2",
          "north" : __DIR__"shandao1",
	]));
	set("objects", ([
           __DIR__"npc/yandaping" : 1,
	]));

	set("sleep_room", 1);
	set("coor/x", -1500);
	set("coor/y", -2055);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}