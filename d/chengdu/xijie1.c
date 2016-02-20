// Room: /d/chengdu/xijie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这里是成都的西大街，熙熙攘攘，热闹非凡，两边是鳞立栉比的店
铺，五颜六色的幌子满街飘荡煞是鲜艳。附近的百姓一般逢十就入城来
赶集，许多商贾也不失时机的推出各种平时买不到的东西。南边是家药
铺，北面则是个占卜的铺子。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"xijie2",
		"west"  : __DIR__"xijie",
		"north" : __DIR__"zhanbu",
		"south" : __DIR__"yaopu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8070);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

