// Room: /d/mobei/buluo2.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "蒙古包");
	set("long", @LONG
蒙古人以游牧为生，所居住的就是以毛毡所作的帐篷，通常称为蒙
古包。帐篷中堆放了几口箱笼，一边是壶弓箭，蒙人自幼长于马上，弓
箭是绝对少不得的。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/zhebie" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : __DIR__"buluo",
	]));
	set("coor/x", -220);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
