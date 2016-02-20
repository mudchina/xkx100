// shanlu2.c 山路
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
前面好象有一个大山谷，走到这里，树木多了些，全都是柏树。
西面是一条弯曲的山路，隐藏在山间，要在夜里还真看不出来。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southwest" : __DIR__"shanlu1",
                "northup"   : __DIR__"cuipinggu",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/badou" : random(2),
        ]));

	set("coor/x", -3140);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
