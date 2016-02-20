// Room: /d/5lt/nroad2.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条南北向的
碎石路上，西边是村支部，门上挂一匾额「无厘头村」。东边是村里花
大力气办的广播站，站里的喇叭正咿咿呀呀播着你不熟悉的音乐。
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "north" : __DIR__"nroad3",
            "south" : __DIR__"shiqiao",
            "west"  : __DIR__"chuandashi",
            "east"  : __DIR__"guangbozhan",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}