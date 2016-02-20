#include <room.h>
inherit ROOM;

void create()
{
	set("short", "康亲王书房");
	set("long", @LONG
这里是康亲王书房，房中书架上整整齐齐地堆放着很多书。不过书
上积了一些灰尘，显然是很久没有动过了。而书橱里的几件精巧玉器却
更显得玲珑剔透，光彩照人。
LONG );
	set("exits", ([
		"south" : __DIR__"neitang",
	]));
	set("objects", ([
		__DIR__"npc/kang" : 1,
	]));
	set("coor/x", -180);
	set("coor/y", 4084);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
