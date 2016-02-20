// Room: /d/wudujiao/road3.c

inherit ROOM;

void create()
{
        set("short", "黄土大道");
        set("long", @LONG
这是一条向南的黄土大道，远处隐约看见一片翠绿的山峦。
路上行人逐渐稀少起来，大路越走越窄，有些地方竟长出了一
片片的杂草。东边似乎有一条岔路。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "southeast" : __DIR__"xiaolu",
                "south"     : __DIR__"shanlu1",
                "north"     : __DIR__"road2",
        ]));

	set("coor/x", -45000);
	set("coor/y", -78000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}