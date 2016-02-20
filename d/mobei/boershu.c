// Room: /d/mobei/boershu.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "博尔术营帐");
	set("long", @LONG
博尔术勇力过人，被称为蒙古人中的英雄，年轻时曾同铁木真一起
追杀马盗，他的营帐中只是几条毡子随便堆放，一杆长枪，一把铁胎弓，
外加九壶铁箭，博尔术箭法神通，上阵带箭之多，无人可及。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boerhu" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"road3",
	]));

	set("coor/x", -220);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
