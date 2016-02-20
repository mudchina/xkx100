inherit ROOM;

void create()
{
	set("name", "全聚德酒楼");
	set("short", "全聚德酒楼二楼");
	set("long", @LONG
这里是雅座，文人学士经常在这里吟诗作画，富商土豪也在这里
边吃喝边作交易。这里也是城里举办喜宴的最佳场所。墙上挂着价格
牌子(paizi)。你站在楼上眺望京城，只觉得心旷神怡。
LONG );
	set("item_desc", ([
		"paizi" : "本店出售烤鸭及上等花雕酒。\n",
	]));
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("objects", ([
		__DIR__"npc/cheng":1,
	]));
	set("coor/x", -190);
	set("coor/y", 4060);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
