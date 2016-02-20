// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "侧房");
	set("long", @LONG
这里就是温家老三温方义的住处，房间整洁，墙上挂着把带鞘的
宝刀，桌子上面铺着一张图，温老三正在专心地看着图上的内容，口
中念念有词。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"zoulang2",
        ]));
	set("objects", ([
		__DIR__"npc/wenfangshan" : 1,
	]));
	set("coor/x", 1590);
	set("coor/y", -1930);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}