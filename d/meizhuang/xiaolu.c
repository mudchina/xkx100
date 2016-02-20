// /d/meizhuang/xiaolu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "蜿蜒小径");
	set("long", @LONG
这条小路的两旁种着无数的梅花，虽然还没到梅花盛开的季节，但
透过这密密的梅林，你似乎已经闻到了阵阵的梅花的幽香，这时你已经
发现你快走到庄园的门口，你暗地里加快了脚步．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"shijie",
		"north" : __DIR__"gate",
	]));
	set("outdoors", "meizhuang");
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1450);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
