// /guanwai/yuzhu.c

inherit ROOM;

void create()
{
	set("short", "玉柱峰");
	set("long", @LONG
白云峰西南，有峰高耸挺秀，多峰突起，形如玉柱。东麓泻出一水，
悬流如线，注入天池，就是古籍所载的“金线泉”了。
LONG );
	set("exits", ([
		"north"      : __DIR__"tiyun",
		"northeast"  : __DIR__"baiyun",
	]));
        set("objects", ([
                __DIR__"npc/she" : 1,
        ]));
	set("outdoors", "changbai");
	set("coor/x", 6170);
	set("coor/y", 5160);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}