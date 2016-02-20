// Room: /d/suzhou/beidajie2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城
外。南边显得很繁忙。东边是一座两层的楼阁，名为春在楼。西面是一
座庙庵，南面是一条笔直的大街，十分繁华。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"jiudian",
		"west"      : __DIR__"zijinan",
		"north"     : __DIR__"beimen",
		"south"     : __DIR__"beidajie1",
	]));
	set("coor/x", 850);
	set("coor/y", -980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
