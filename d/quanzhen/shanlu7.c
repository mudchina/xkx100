// /d/quanzhen/shanlu7.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山间小径");
        set("long", @LONG
这是一条位於终南山脚，鲜为人知的小径。四周古木叁天，树林
苍翠，遍地山花，枝头啼鸟唱和不绝。往南可看到一条小河。往东
可通往山林深处。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "east"  : __DIR__"shanlu6",
                "south" : __DIR__"xiaohebian",
        ]));

	set("coor/x", -3160);
	set("coor/y", 10);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
