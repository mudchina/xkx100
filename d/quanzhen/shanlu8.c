// /d/quanzhen/shanlu8.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一条非常崎岖难行的山路，一路蜿蜒盘山ㄦ上，沿途均是葱
郁的古柏山林，蔚然森秀。在此处可眺望终南山的景色，只见山险岭
峻，山川毓秀，往南下是一条道路。往北上走是一条蜿蜒的山路。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"   : __DIR__"shanlu9",
                "southdown" : __DIR__"shanlu4",
        ]));

	set("coor/x", -3130);
	set("coor/y", 10);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
