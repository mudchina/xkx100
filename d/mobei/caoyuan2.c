// Room: /d/mobei/caoyuan2.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "蒙古草原");
	set("long", @LONG
广袤无垠的漠北草原，成群的牛羊的白云下奔跑，骑着骏马的游牧
人挥舞着手中的长鞭，塞北的草原。南边去是到中原，北面过去就是铁
木真的营帐。
LONG);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"southeast" : __DIR__"caoyuan3",
		"north"     : __DIR__"caoyuan",
	]));
	set("coor/x", -230);
	set("coor/y", 5160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
