// Room: /d/wudujiao/huayuan3.c

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这里是个花园，一年四季都生长着各种奇异的花草，在阳光下发出七彩
妖艳的光辉。花园里一片沉寂，竟看不到一只蜜蜂或蝴蝶飞舞。旁边有一座
小亭子。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"huating3",
                "south" : __DIR__"huayuan1",
        ]));

	set("coor/x", -44900);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}