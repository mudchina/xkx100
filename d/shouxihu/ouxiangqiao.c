// Room: /yangzhou/ouxiangqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","藕香桥");
	set("long",@LONG
藕香桥旧名法海桥，位于莲性寺东南侧，东西跨瘦西湖，支流湖道
栽种荷花。开莲花埂新河，建莲花桥后，湖上画舫皆过莲花桥，不复过
法海桥。
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"northwest" : __DIR__"lianxingsi",
		"southeast" : __DIR__"taohuawu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}