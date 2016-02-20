// Room: /city/dongmen.c

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "得胜山");
	set("long", @LONG
得胜山是当年岳飞大破金兵之处，现在的山由已经长满了密密的树
木，一般走到这块山脚下的空地就爬不上去了。中间空的大约是几丈见
方，地上的草也没有，看得出，来此的人还不少。
LONG );
	set("outdoors", "yangzhoue");
	set("exits", ([
		"west" : __DIR__"jiaowai1",
	]));

	set("no_clean_up", 0);
	set("coor/x", 75);
	set("coor/y", -20);
	set("coor/z", 3);
	setup();
	replace_program(ROOM);
}