// Room: /d/chengdu/huanhuaxi2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "浣花溪");
	set("long",@LONG
季节虽然已经是深秋，但日正当中的阳光，仍旧是十分炎热的。四
周是一片芙蓉树，远山隐在云雾之中，恍若迷离的美人，不远处有着，
一丛丛的树林，有一条溪流，沿着林旁蜿蜒流去。这里已是浣花溪，往
东就是北大街了。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southwest" : __DIR__"huanhuaxi1",
		"northeast" : __DIR__"beijie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -2950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


