// Room: /d/mobei/road1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "营帐间");
	set("long", @LONG
举目所见，那都是密密麻麻的营帐，一个连着一个，蒙古部落游牧
为生，平时所住就是蒙古包，拆解方便。两边有道通向几个帐幕，分别
是亲卫和大将们的住所，南面是辕门，几面旌旗迎风招展。
LONG);
	set("outdoors","mobei");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/qinwei1" : 1,
	]));
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"road",
		"east" : __DIR__"road2",
		"west" : __DIR__"road3",
		"south" : __DIR__"yuanmen",
	]));
	set("coor/x", -210);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
