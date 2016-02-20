//ROOM: /d/yanziwu/shuwu.c

inherit ROOM;

void create()
{
	set("short", "翰墨书屋");
	set("long",@LONG
屋中一架架紫竹搭成的书架倚墙而立，书架上摆满了经史典籍。屋
子正中央是一张书桌，桌上琴棋俱备，笔墨纸砚一应俱全，墙上挂着一
幅条幅(tiaofu)。大名鼎鼎的慕容公子常在这里读书写字。
LONG );
	set("exits", ([
		"east" : __DIR__"lanyue",
		"north": __DIR__"canheju",
		"south": __DIR__"shangyu",
	]));

	set("item_desc",([
		"tiaofu" : "
	       光洒菱湖天欲晚，
	       复国无计隐寒潭。
	       大梦未觉身已老，
	       燕语声中空笑谈。\n\n\n ",
	]));
	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1550);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}