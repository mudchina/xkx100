// Room: /d/quanzhou/westroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "刺桐西路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。西边便是
著名的开元寺及西门吊桥。北边有一家杂货铺。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"westroad2",
		"east"  : __DIR__"guangchang",
		"north" : __DIR__"zahuopu",
	]));
	set("coor/x", 1840);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
