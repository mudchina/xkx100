// Room: /d/chengdu/dangpu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，
柜台上摆着一个牌子 (paizi)，柜台后坐着当铺老板燕六，一双精明的
眼睛上上下下打量着你。
LONG	);
	set("no_fight", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "公平交易\n",
	]));
	set("exits", ([
		"north" : __DIR__"xijie",
	]));
	set("objects" , ([
		__DIR__"npc/yanliu" : 1,
	]));
	set("coor/x", -8080);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

