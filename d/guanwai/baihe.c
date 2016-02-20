// /guanwai/baihe.c

inherit ROOM;

void create()
{
	set("short", "白河");
	set("long", @LONG
这里是长白山下的一个小村，只有四，五间粗陋的小木屋。这里并
没有固定的居民，木屋都是进山采参的参客所盖，为的是在进山前能在
这里好好的休息一下。东面就是巍峨耸立的长白大山。
LONG );
	set("exits", ([
		"west"  : __DIR__"caoguduo",
		"east"  : __DIR__"milin1",
		"north" : __DIR__"xiaowu",
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "changbai");
	set("coor/x", 6140);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
