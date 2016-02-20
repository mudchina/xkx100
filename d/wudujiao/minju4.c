// Room: /d/wudujiao/minju4.c

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
这是一户普通的农家，屋里没有什么象样的摆设。墙边摆放着一些
农具，屋正中摆着一张八仙桌，村长正拿着旱烟袋坐在桌边抽着。
LONG
        );

        set("exits", ([
                "out" : __DIR__"cun5",
        ]));
        set("objects", ([
                __DIR__"npc/cunzhang": 1,
        ]));

	set("coor/x", -44950);
	set("coor/y", -80990);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}