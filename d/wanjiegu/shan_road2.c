// Room: /t/wanjiegu/shan_road2.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一条山间小路，两边山坡上张了许多树木，北风吹过，发
出沙沙的响声。路上张着许多杂草，看起来这里很少有人走动。
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "westdown" : __DIR__"shan_road3",
            "eastdown" : __DIR__"shan_road1",
        ]));
        set("objects", ([
            __DIR__"npc/bee" : 2,
        ]));
//        set("no_clean_up", 0);

	set("coor/x", -50090);
	set("coor/y", -19010);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}