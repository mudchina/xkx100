// Room: /d/mobei/hill.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "小土山");
	set("long", @LONG
只是泥土高起的一个土丘，却是这片天空下最高的一处，东西南北
都是无边的蒙古草原，围绕着土丘的除了几条小路外，就是低矮的灌木
丛，地上散落着一些断裂的箭羽，森森的白骨和一些残缺的布帛。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guojing" : 1,
	]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"guanmu",
	]));
	set("outdoors","mobei");

	set("coor/x", -260);
	set("coor/y", 5160);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
