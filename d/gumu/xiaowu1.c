// xiaowu1.c 小屋
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
你走进了一间小屋，房间很小，除了一张小床放不下别的东西了。
床上好象有几件叠得整整齐齐的粗布衫，洗的干干净净。
LONG	);
	set("exits", ([
		"south" : __DIR__"mudao10",
		"north" : __DIR__"mudao04",
	]));
	set("objects", ([
		__DIR__"obj/fengjiang" : 3,
		__DIR__"obj/fengmi" : 1,
	]));
	set("coor/x", -3220);
	set("coor/y", -10);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

