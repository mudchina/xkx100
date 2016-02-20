// /d/quanzhen/shanlu13.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一条非常崎岖难行的山路，一路蜿蜒盘山ㄦ上，沿途均是葱
郁的古柏山林，蔚然森秀。在此处可眺望终南山的景色，只见山险岭
峻，山川毓秀，不少鸟ㄦ在枝头高声啼唱不绝。往北下是草堂寺。往
西上是一条山路。往东是一块广大的空地。往西北通往后山下。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"     : "/d/gumu/shanlu6",
                "northdown"  : __DIR__"caotangsi",
                "northwest"  : __DIR__"shandao1",
                "eastdown"   : __DIR__"daxiaochang",
        ]));

	set("coor/x", -3180);
	set("coor/y", 110);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}
