// Room: /d/mobei/wokuotai.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "窝阔台营帐");
	set("long", @LONG
窝阔台是铁木真的三儿子，也是将来的大汗。他为人仁和宽厚，和
诸兄弟及亲兵大将也均交好。他的营帐也十分朴素。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/wokuotai" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"road",
	]));
	set("coor/x", -200);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
