// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，北边隐约可见到扬州城的城墙。此处往东
南望去，可以看到一个市镇。
LONG );
	set("outdoors", "sanbuguan");
	set("exits", ([
		"south" : __DIR__"wdroad3",
		"north" : __DIR__"wdroad1",
		"southeast" : "/d/yixing/yixing",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
