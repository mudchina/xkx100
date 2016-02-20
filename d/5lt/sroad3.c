// Room: /d/5lt/sroad3.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条南北向的
碎石路上，西边是一家打铁铺，叮叮当当的声音老远就能听到。东面是
村里的体彩中心。
LONG);
        set("exits", ([ /* sizeof() == 3 */
            "north" : __DIR__"sroad2",
            "west"  : __DIR__"datiepu",
            "east"  : __DIR__"tczhongxin",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}