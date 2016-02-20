// Room: /d/nanshaolin/shanlu3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石阶路");
	set("long", @LONG
这里已经没什么树林了。两边是隆起的山脊。南边山谷通往山外，
远远看去，是一片马尾松的海洋。北面山坳里，连片的建筑窝在山谷里，
好大一片禅林。这里路近少林，路面都铺上了石板。
LONG);

	set("exits", ([
		"south" : __DIR__"shanlu2",
		"north" : __DIR__"shifang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6330);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



