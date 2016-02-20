// yushanang.c
inherit ROOM;

void create()
{
	set("short", "御膳房");
	set("long", @LONG
远远就能闻到一阵阵香味从这儿飘出. 这里是御膳房. 闲杂人等不
能在此出入. 一张张长桌上摆着天下美味, 无不令人垂涎三尺. 可这是
皇上吃的, 你想也甭想.
LONG
	);

	set("exits", ([
		"north" : __DIR__"jianting",
		"south" : __DIR__"houyuan",
		"west"  : __DIR__"qinghedian",
	]));
	set("objects", ([
		__DIR__"npc/taijian":1,
		__DIR__"obj/yuchi" : 2,
	]));

	set("coor/x", -180);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
