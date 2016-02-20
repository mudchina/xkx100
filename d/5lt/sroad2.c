// Room: /d/5lt/sroad2.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条南北向的
碎石路上，西面有个邮局，不时有送信的邮差骑着脚踏车吆喝着从你身
边掠过。东边就是“青蛙诊所”了。
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"yanwuqiao",
            "south" : __DIR__"sroad3",
            "west"  : __DIR__"youju",
            "east"  : __DIR__"zhensuo",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
