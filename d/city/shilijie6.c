// Room: /yangzhou/shiliji6.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里长街");
	set("long",@LONG
这里就是张佑诗中写的「十里长街市井连，月明桥上望神仙」的十
里长街。长街宽达三十丈，青砖铺地，东边一道泄水沟。街中心种有槐
树，分行人以左右而行。西边是官河，岸边相间种有绿柳碧桃，倒影水
面，摇曳风中。东边临街的屋子挂有招牌，是一家老字号的药铺。西边
是一家杂货铺。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"zahuopu",
		"east"  : __DIR__"yaopu",
		"south" : __DIR__"shilijie7",
		"north" : __DIR__"shilijie5",
	]));
	set("objects", ([
		"/d/dali/npc/duanyu" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}