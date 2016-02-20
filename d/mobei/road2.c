// Room: /d/mobei/road2
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "营帐间");
	set ("long", @LONG
举目所见，那都是密密麻麻的营帐，一个连着一个，蒙古部落游牧
为生，平时所住就是蒙古包，拆解方便。南边是亲卫营，北面的营帐前
拴了几条獒犬。东面的营帐是术赤的住处。
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"road1",
		"east"  : __DIR__"qinwei",
		"south" : __DIR__"shuchi",
		"north" : __DIR__"chahe",
	]));
	set("coor/x", -200);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
