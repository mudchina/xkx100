// Room: /d/5lt/nroad3.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条南北向的
碎石路上，西边是羽毛球馆，据说里面卧虎藏龙，高手如云。东边是放
映场，有了空暇村民们喜欢聚在一起边看电影边叨家常。
LONG);
        set("exits", ([ /* sizeof() == 3 */
            "south" : __DIR__"nroad2",
            "west"  : __DIR__"qiuguan",
            "east"  : __DIR__"fychang",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}