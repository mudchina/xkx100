// Room: /d/taishan/riguanroad1.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "日观山路");
	set("long", @LONG
这里是日观峰小路，自峰顶东下，联结东天门。此处山势陡峭，两
边下临深谷，一不小心都会掉了下去。
LONG );
	set("exits", ([
		"eastdown" : __DIR__"dongling",
		"westup"   : __DIR__"riguan",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 380);
	set("coor/y", 770);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}
