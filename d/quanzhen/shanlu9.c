// /d/quanzhen/shanlu9.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一条非常崎岖难行的山路，一路蜿蜒盘山ㄦ上，沿途均是葱
郁的古柏山林，蔚然森秀。在此处可眺望终南山的景色，只见山险岭
峻，山川毓秀。往北上走是金莲阁。往南走是崎岖的山路。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"   : __DIR__"jinliange",
                "southdown" : __DIR__"shanlu8",
        ]));

	set("coor/x", -3130);
	set("coor/y", 20);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
