// Room: /d/mobei/road.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "营帐间");
	set("long", @LONG
举目所见，那都是密密麻麻的营帐，一个连着一个，蒙古部落游牧
为生，平时所住就是蒙古包，拆解方便。北面的一个营帐前一杆高高的
长杆上飘着几缕白毛，此旗所在处就是大汗居处。
LONG);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/qinwei1" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"yinzhang",
		"south" : __DIR__"road1",
		"east"  : __DIR__"wokuotai",
		"west"  : __DIR__"tuolei",
	]));

	set("coor/x", -210);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
