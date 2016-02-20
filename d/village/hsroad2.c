// hsroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，南边隐约可见到扬州城的城墙。北面两条土路分
岔通向山里。
LONG );
        set("outdoors", "village");
	set("exits", ([
		"south"     : __DIR__"hsroad1",
		"northwest" : __DIR__"hsroad3",
		"northeast" : "/d/huashan/jzroad1",
	]));
	set("no_clean_up", 0);

	set("coor/x", -960);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}