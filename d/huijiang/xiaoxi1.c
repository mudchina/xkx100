// Room: /d/huijiang/xiaoxi1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "小溪流");
	set("long", @LONG
在差刺交错的岩石之间流淌的一条小溪流。清澈的河底是光滑的鹅
卵石。溪流两边的树木开始多了起来，溪水转弯绕过一块高地，忽然眼
前一片银瀑，水声轰轰不绝，匹练有如自天而降，飞珠溅玉，顿成奇观。
LONG
	);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"xiaoxi",
		"westup"    : __DIR__"xiaoxi2",
	]));
	set("objects", ([ /* sizeof() == 1 */
	]));
	set("coor/x", -50020);
	set("coor/y", 9010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
