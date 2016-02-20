// Room: /d/wuxi/dangpu.c
// Winder 2000/02/22 

inherit ROOM;

int do_quit();
void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，
柜台上摆着一个牌子 (paizi)，柜台后坐着冯老板，一双精明的上上下
下打量着你。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "公平交易\n
sell        卖 
buy         买
value       估价
",
	]));
	set("objects", ([
		__DIR__"npc/feng" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"westroad1",
	]));

	set("coor/x", 360);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
