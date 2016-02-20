#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","山洞");
	set("long",@LONG
这洞里黑黝黝的，不知道里面住着什么武林异士，还是有什
么山魈木怪。是不是再往里走呢？你心里拿不定主意。
LONG
	);
	set("exits",([
		"north":__DIR__"maigu",
		"out":__DIR__"dongkou",
	]));
	set("coor/x", -400);
	set("coor/y", -440);
	set("coor/z", 0);
	setup();
}
	