// /d/quanzhen/shanlu10.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一条非常崎岖难行的山路，一路蜿蜒盘山ㄦ上，沿途均是葱
郁的古柏山林，蔚然森秀。在此处可眺望终南山的景色，只见山险岭
峻，山川毓秀，不少鸟ㄦ在枝头高声啼唱不绝。往东下是莲花寺。往
西上是一条山路。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"    : __DIR__"riyueyan",
                "eastdown"  : __DIR__"jinliange",
        ]));

	set("coor/x", -3140);
	set("coor/y", 30);
	set("coor/z", 60);
	setup();
        replace_program(ROOM);
}
