// /kaifeng/road5.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
御街是横贯开封的主要街道，也是皇上出巡的要道。街道两边店铺
亭台不断，小贩叫卖，行人来往，车马喧哗，一派繁华，南边的高桥就
是州桥，西面是龙亭寺。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west"    : __DIR__"tingyuan",
		"north"   : __DIR__"road6",
		"southup" : __DIR__"road4",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
