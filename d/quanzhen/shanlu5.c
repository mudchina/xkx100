// /d/quanzhen/shanlu5.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山间小径");
        set("long", @LONG
这是一条位於终南山脚，鲜为人知的小径。四周古木叁天，树林
苍翠，遍地山花，枝头啼鸟唱和不绝。往东可看到一条道路。往西北
可通往山林深处。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "east"      : __DIR__"shanlu4",
                "northwest" : __DIR__"shanlu6",
        ]));

	set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
