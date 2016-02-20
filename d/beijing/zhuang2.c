inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条小路上。前面道路崎岖，行人很少。前方隐约有房屋可
见。
LONG );
	set("exits", ([
		"south" : __DIR__"zhuang1",
		"north" : __DIR__"zhuang3",
	]));
	set("objects", ([
		"/d/wudang/npc/tufei1" : 1,
	]));
 	set("outdoors", "huabei");
	set("coor/x", 100);
	set("coor/y", 4600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

