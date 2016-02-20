// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "侧房");
	set("long", @LONG
这里就是温家老五温方南的住处，他是个爱附庸风雅的人，正
拿着本诗集摇头晃脑地读着。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"zoulang6",
        ]));
        set("objects", ([
		__DIR__"npc/wenfangnan" : 1,
		__DIR__"npc/yahuan" : 1,
        ]));
	set("coor/x", 1630);
	set("coor/y", -1930);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}