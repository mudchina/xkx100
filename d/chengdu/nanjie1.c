// Room: /d/chengdu/nanjie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这条街上，双人合抱的大树在街边十步一株，整整齐齐，青石铺就
的街面打扫得干干净净。你没事最好不要在这里溜达，因为这里是成都
的王府大街。西边一座牌楼，金碧辉煌，令人目为之眩，这便是梁王府。
东边则是一些民居。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west"  : __DIR__"wang",
		"east"  : __DIR__"minju",
		"south" : __DIR__"nanjie2",
		"north" : __DIR__"guangchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

