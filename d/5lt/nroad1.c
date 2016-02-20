// Room: /d/5lt/nroad1.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条南北向的
碎石路上，西边是一间面包屋，刚出炉面包的阵阵香味让你垂涎欲滴。
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "north" : __DIR__"shiqiao",
            "south" : __DIR__"center",
            "west"  : __DIR__"mianbaowu",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}