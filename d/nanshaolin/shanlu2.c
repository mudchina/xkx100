// Room: /d/nanshaolin/shanlu2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石阶路");
	set("long", @LONG
满目望去，都是连片的马尾松。松树与松树似乎都挤在一块生长，
阳光到这里变得格外黯淡，只在地上留下斑驳的碎影。静听不远处格的
一声，象是松枝断落的声音。这里路近少林，路面都铺上了石板。
LONG);

	set("exits", ([
		"southdown" : __DIR__"ting",
		"north"     : __DIR__"shanlu3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6340);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



