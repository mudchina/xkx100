// Room: /d/mobei/xiaolu.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "小路");
	set ("long", @LONG
林中的一条小道，高矮不平，时而要从一些挡路的灌木中穿过，七
拐八歪的不远，一座山崖平地而起，山崖半截深入云雾之中，自来无人
能得上去。
LONG);
	set("exits", ([ /* sizeof() == 2 */
		"north"    : __DIR__"downxuanya",
		"eastdown" : __DIR__"shulin4",
	]));
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("coor/x", -250);
	set("coor/y", 5200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
