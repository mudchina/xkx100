inherit ROOM;

void create()
{
	set("short", "朝阳路");
	set("long", @LONG
这是一条青石路，一路走来见不到几个行人。东南边是东门。朝阳
门在西北边。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"northwest" : __DIR__"chaoyang",
		"southeast" : __DIR__"dongmen",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


