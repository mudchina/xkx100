// Room: /d/mobei/road3
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "营帐间");
	set ("long", @LONG
举目所见，那都是密密麻麻的营帐，一个连着一个，蒙古部落游牧
为生，平时所住就是蒙古包，拆解方便。两边有道通向几个帐幕，分别
是亲卫和大将们的住所。
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		"east"  : __DIR__"road1",
		"west"  : __DIR__"qinwei2",
		"south" : __DIR__"boershu",
		"north" : __DIR__"muhuali",
	]));
	set("coor/x", -220);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
