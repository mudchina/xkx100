// Room: /d/mobei/caoyuan4.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "蒙古草原");
	set ("long", @LONG
乌云从西面的天空快速地移动过来，乌云中有闪点在不住闪动，乌
云下就是广袤的蒙古草原，远处的闪电照亮了一片连绵的营帐，那就是
铁木真的部落。
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"caoyuan5",
		"south" : __DIR__"caoyuan",
	]));
	set("coor/x", -230);
	set("coor/y", 5180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
