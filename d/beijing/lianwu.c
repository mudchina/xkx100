// lianwu.c 练武房

inherit ROOM;

void create()
{
        set("short", "练武房");
        set("long", @LONG
这里是天地会的练武房，壁上挂着一些熊皮、虎皮、花叶豹皮，地
下青砖地已经破损得很零碎了。墙角倚着一些兵器。几个天地会会众正
盘膝打坐。
LONG );
        set("exits", ([
                "east" : __DIR__"dating",
        ]));
        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 6
        ]));
	set("coor/x", -213);
	set("coor/y", 4015);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}