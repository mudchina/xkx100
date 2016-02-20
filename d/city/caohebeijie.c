// Room: /yangzhou/caohebeijie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","草河北街");
	set("long",@LONG
这是草河小街的尽头了，北边就是瘦西湖了。西边是扬州府的府学
「资政书院」，西北边是魁星阁。这里游人稀少，只有几个书生匆匆而
过，府学的门口有几个顽劣学童在嬉笑打闹，给这寂静的街道添了几分
生气。北边是一个典当行，大概只有一些穷书生常光临那里。南边是一
个小广场。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"zizheng",
		"east"      : __DIR__"hongqiao",
		"south"     : __DIR__"xiaosquare",
		"north"     : __DIR__"diandanghang",
		"northwest" : __DIR__"kuixingge",
		"southwest" : __DIR__"petroom",
	]));
	set("objects", ([
		__DIR__"npc/qiuxingxing" : 1,
		__DIR__"npc/yangleishi" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
