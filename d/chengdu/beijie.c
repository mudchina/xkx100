// Room: /d/chengdu/beijie.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这条街上双人合抱的梧桐十步一株，整整齐齐，青石铺就的路面打
扫得干干净净。东边是个珠宝铺，西边则是闻名天下的武威镖局。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"zhubaopu",
		"west"  : __DIR__"biaoju",
		"south" : __DIR__"beijie1",
		"north" : __DIR__"northgate",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 1,
	]));
	set("coor/x", -8050);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

