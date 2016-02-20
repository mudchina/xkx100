// Room: /yangzhou/shiliji1.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里长街");
	set("long",@LONG
走在十里长街，见到街边酒楼茶肆，重楼高阁，互相临映，每当入
夜，各酒馆茶楼都挑出灯笼，行人游客缓缓而行，出入酒楼，更有女子
盛妆，进出茶肆，看到此情此景，不禁想起王建的诗句：「夜市千灯照
碧云，高楼红袖客纷纷」，见到如此繁华的扬州，不知盛唐的扬州更是
何种盛况。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"xiaobaozhai",
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"shilijie2",
		"north" : __DIR__"beimendajie",
	]));
	set("objects", ([
		CLASS_D("quanzhen") + "/youfang" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
