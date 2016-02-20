// /d/quanzhen/shanlu6.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山间小径");
        set("long", @LONG
这是一条位於终南山脚，鲜为人知的小径。四周古木叁天，树林
苍翠，遍地山花，枝头啼鸟唱和不绝。往西和东南可通往山林深处。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southeast" : __DIR__"shanlu5",
                "west"      : __DIR__"shanlu7",
        ]));

	set("coor/x", -3150);
	set("coor/y", 10);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
