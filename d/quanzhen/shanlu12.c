// /d/quanzhen/shanlu12.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山道");
        set("long", @LONG
此段山路是沿着峭壁而开凿出来的，特别崎岖难行。有时峭壁边
必须面贴山璧，侧身而过。尤其当山凤吹来时，更需特别小心，不然
一失足，就要掉进万丈深渊了。往北是一块广大的空地。往南下是一
块巨岩。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"    : __DIR__"daxiaochang",
                "southdown"  : __DIR__"juyan",
        ]));

	set("coor/x", -3170);
	set("coor/y", 100);
	set("coor/z", 110);
	setup();
        replace_program(ROOM);
}
