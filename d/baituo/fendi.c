// Room: /d/baituo/fendi.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "坟地");
	set("long", @LONG
这里是荒凉阴森的荒坟地。一个坟包连着一个坟包。有的坟包上还
插着一支竹竿，扯着一条布带，有的坟包根本什么都没有。几只老鸦站
在坟地里的枯枝上，不时地啼叫两声。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"southwest" : __DIR__"xiaolu1",
		"north"     : __DIR__"mumen",
	]));
	set("objects" , ([
		__DIR__"npc/guafu" : 1,
	]) );
	set("coor/x", -49960);
	set("coor/y", 20000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
