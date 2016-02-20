// Room: /d/mobei/muhuali.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "木华黎营帐");
	set("long", @LONG
木华黎是蒙古的智者，是大汗的军师。他的营帐中只有几条毡子随
便堆放，其他地方到处都是书。据说蒙古文字就是他草创的。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/muhuali" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"road3",
	]));

	set("coor/x", -220);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
