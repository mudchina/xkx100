// wdroad4.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，四周静悄悄的。西边是一条大道，东边是
好大的一片树林。往南还有一条大道，掩映在密密的树林中。
LONG );
	set("outdoors", "sanbuguan");
	set("exits", ([
		"southwest"    : __DIR__"wdroad5",
		"east"    : "/d/xiaoyao/shulin3",
		"southup" : "/d/henshan/hsroad1",
		"north"   : __DIR__"wdroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
