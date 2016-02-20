// shishi1.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
这是一个石头砌成的房间，因为好久没有人来过，散发着一些很难
闻的气味，房间中到处可以看到蛛丝和虫迹。
LONG );
	set("exits", ([
		"east" : __DIR__"shiji1",
	]));
	set("objects",([
		__DIR__"obj/putuan" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -50040);
	set("coor/y", -21040);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}