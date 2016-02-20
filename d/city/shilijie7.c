// Room: /yangzhou/shiliji7.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里长街");
	set("long",@LONG
这里就是烟花三月的十里长街。长街宽达三十丈，青砖铺地，东边
一道泄水沟。街中心种有槐树，分行人以左右而行。西边是官河，岸边
相间种有绿柳碧桃，倒影水面，摇曳风中。东边是一家新入江湖的少年
常去的武馆。西边是一家打铁铺，叮叮当当的声音老远就能听到。北面
通向中心广场，南面一直走就出南门了。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"datiepu",
		"east"  : "/d/wuguan/wg_guanmen",
		"south" : __DIR__"nanmendajie",
		"north" : __DIR__"shilijie6",
	]));
	set("objects", ([
		CLASS_D("shaolin") + "/tuoboseng" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
