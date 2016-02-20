inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条小路上。前面道路崎岖，行人很少。
LONG );
	set("exits", ([
		"southwest" : __DIR__"road1",
		"north"     : __DIR__"zhuang2",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
 	set("outdoors", "huabei");
	set("coor/x", 100);
	set("coor/y", 4500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

