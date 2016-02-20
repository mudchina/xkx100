// Room: /d/fuzhou/luoxingta.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "罗星塔");
	set("long", @LONG
罗星塔矗立马江畔。这里是东方大港，相传郑和七下西洋，即在此
造舟铸钟，放洋西海的。西洋水手亦将此塔做为到达东方的认记。塔上
有铭文对联“朝朝朝朝朝朝夕  长长长长长长消”。
LONG );
	set("exits", ([
		"northup" : __DIR__"gushan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1890);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
