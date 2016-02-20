// Room: /d/huanggong/wenhua.c

inherit ROOM;

void create()
{
	set("short", "文华殿");
	set("long", @LONG
这里是文华殿, 在这陈列着许许多多千奇百怪的奇珍异宝. 这里是
皇帝举行经筵讲习的地方, 每年春秋两季, 由经筵讲官在此向皇帝讲解
四书五经, 再由皇帝复讲一遍, 并有王公大臣陪读.
LONG
	);
	set("exits", ([
		"west"      : __DIR__"guangchang",
		"east"      : __DIR__"donghuamen",
		"south"     : __DIR__"wenyuange",
		"southeast" : __DIR__"guoshiguan",
		"southwest" : __DIR__"neigedatang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}