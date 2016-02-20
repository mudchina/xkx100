// Room: /d/mobei/buluo1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "铁木真部落");
	set("long", @LONG
铁木真部落是当今大漠最强盛的一族，隐有一统蒙古之势。练绵的
帐蓬望不到边，来往的人们手中多拿着武器，向北去就是辕门。东西两
边都是部落中人居住的蒙古包。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/menggukid" : 2,
	]));
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"menggubao1",
		"west"  : __DIR__"menggubao",
		"north" : __DIR__"yuanmen",
		"south" : __DIR__"buluo",
	]));
	set("outdoors", "mobei");
	set("coor/x", -210);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
