// Room: /d/songshan/tayuan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "塔院");
	set("long", @LONG
法王寺北山坡上，是法王寺塔院。院内有十五层密檐方塔，高近二
十丈，造型优美。院内其它三座单檐墓塔，亦玲珑秀丽。
LONG );
	set("exits", ([
		"southdown" : __DIR__"fawangsi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 820);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
