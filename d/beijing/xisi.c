inherit ROOM;

void create()
{
	set("short", "西四北大街");
	set("long", @LONG
这是一条长长的街道。东边就是游人们常去的文庙，那里长年香火不断，
烟雾缭绕。南边是西单北大街。
LONG );
  set("outdoors", "city2");
	set("coor/x", -220);
	set("coor/y", 4070);
	set("coor/z", 0);

	set("exits", ([
		"north" : __DIR__"xisi2",
		"east" : __DIR__"wenmiao",
		"south" : __DIR__"xidan1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


