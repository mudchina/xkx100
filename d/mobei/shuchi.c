// Room: /d/mobei/shuchi.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "术赤营帐");
	set("long", @LONG
术赤是铁木真的大儿子，他的营帐布置得比较豪华，连挂在壁上的
弓箭都用金漆仔细描过。一张大红的毡子铺在帐幕中间，矮几上的金杯
装满了血色的葡萄酒。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/shuchi" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"road2",
	]));
	set("coor/x", -200);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
