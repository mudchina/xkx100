// Room: /d/wuxi/northroad1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
一条典型的江南街道，地面虽然是用小青砖铺成，但也是十分地平
整。两边的店铺飞檐瓦当，无不透着水乡的秀气。大街上操着南腔北调
的人们行色匆匆，南边就是无锡城的中心广场。东边是江南名刹崇安寺，
来自各地的人们进进出出，香火十分旺盛。西边是一家专售无锡惠山泥
人的店铺，是来这里的外地旅客最爱光顾的地方。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"jinlianqiao",
		"south" : __DIR__"guangchang",
		"east"  : __DIR__"chongansi",
		"west"  : __DIR__"nirenpu",
	]));
	set("objects", ([
			__DIR__"npc/lady" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}