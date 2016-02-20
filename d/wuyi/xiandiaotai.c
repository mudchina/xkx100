// Room: /d/wuyi/xiandiaotai.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "仙钓台");
	set("long", @LONG
这里位于四曲溪北，又称钓鱼台。从水中向上耸立，尖峭的岩凤，
直插云天，犹如一个头戴竹笠、临溪垂钓的仙翁。“钓仙姜子牙四曲犯
难，拗断钓竿，誓不垂钓”指的就是这里。至今岩孔中钓竿仍在。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"shijianshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -4990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

