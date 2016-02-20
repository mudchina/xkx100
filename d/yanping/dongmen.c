// Room: /d/yanping/xiaoshuimen.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "东门");
	set("long", @LONG
东门惯称“小水门”。因为东门下便是码头，百姓称之“小水门”
是相对延津渡上延福门那个“大水门”而言的。延平城依山傍水，码头
都是大块的花岗岩砌就，城墙就是大块的青砖垒起来的了。东门外，一
座浮桥横跨两岸。
LONG );
	set("exits", ([
		"north"    : __DIR__"fengguanyan",
		"south"    : __DIR__"road1",
		"westup"   : __DIR__"meishanpo",
		"eastdown" : __DIR__"fuqiao1",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1520);
	set("coor/y", -6170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
