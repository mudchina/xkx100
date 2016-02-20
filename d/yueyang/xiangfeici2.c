// Room: /d/yueyang/xiangfeici2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "湘妃祠前殿");
	set("long", @LONG
前殿是这个三进湘妃祠的第二进，有武将镇守，两边是厢房。金字
垛的骑马墙，上雕有蝙蝠寿桃，蝠是福的同声，为福寿的意思，
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"xiangfeici1",
		"north" : __DIR__"xiangfeici3",
	]));
	set("coor/x", -1660);
	set("coor/y", 2320);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
