// shandao1.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山道");
        set("long", @LONG
此段山路是沿着峭壁而开凿出来的，特别崎岖难行。有时峭壁边
必须面贴山璧，侧身而过。尤其当山凤吹来时，更需特别小心，不然
一失足，就要掉进万丈深渊了。往东南是一块广大的空地。往北下通
往后山脚，远远可以望见一个较大的湖。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southeast"   : __DIR__"shanlu13",
                "northdown"   : __DIR__"shandao2",
        ]));

	set("coor/x", -3190);
	set("coor/y", 120);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}
