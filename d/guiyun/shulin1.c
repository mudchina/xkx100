// Room: /d/guiyun/shulin1.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long",@LONG
这是一片小树林。地面上绿草如荫，茂密地生长着。树叶的缝隙间
偶尔会有一只小鸟被惊起，四周十分静寂。
LONG
);
	set("exits",([
		"west"  : __DIR__"shulin2",
		"east"  : __DIR__"shulin3",
		"south" : __DIR__"caodi1",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}

