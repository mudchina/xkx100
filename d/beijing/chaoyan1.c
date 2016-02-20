inherit ROOM;

void create()
{
	set("short", "朝阳路");
	set("long", @LONG
这是一条东西走向的大道。西边人声鼎沸，十分热闹。东边就是朝
阳门。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"wangfu2",
		"east" : __DIR__"chaoyang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -170);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
