// Room: /d/heimuya/road3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条黄土路上。西面望去，隐隐可以看到平定州。望东，北
京城快到了。
LONG );
	set("outdoors", "huabei");
	set("exits", ([
		"east" : "/d/beijing/ximenwai",
		"west" : __DIR__"pingdingzhou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2000);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
