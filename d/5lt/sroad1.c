// Room: /d/5lt/sroad1.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条南北向的
碎石路上，西面有个大酒楼，金色的锦旗迎风飘扬，只见上书四个大字
格外醒目“悦华酒楼”。东面看起来是个茶馆，一个个衣着光鲜的人从那
里进进出出。
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"center",
            "south" : __DIR__"yanwuqiao",
            "west"  : __DIR__"jiulou1",
            "east"  : __DIR__"chaguan",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
