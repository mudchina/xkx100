// Room: /yangzhou/pingtai5.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","平台");
	set("long",@LONG
熙春台前平台，临水二层，白石为砌，围以雕栏，再现昔日“横可
跃马，纵可方轨”的风貌。右通重檐亭，左达十字阁。楼台亭阁之间，
列置湖石花台，种植“金玉满堂春富贵”的桂、玉兰、牡丹，更显得庄
重富丽。露台左侧设诗碑一座：“青山隐隐水迢迢，秋尽江南草未凋，
二十四桥明月夜，玉人何处教吹箫”。
LONG );
	set("outdoors", "shouxihu");
	set("objects", ([
		"/d/village/npc/kid" : 1,
	]));
	set("exits", ([
		"north"  : __DIR__"shizige",
		"south"  : __DIR__"chongyanting",
		"westup" : __DIR__"xichuntai",
		"east"   : __DIR__"ershisiqiao",
	]));
	set("coor/x", -50);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}