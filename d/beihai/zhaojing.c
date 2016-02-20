// /d/beihai/zhaojing.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "昭景门");
	set("long", @LONG
团城为一高台，圆形，台高丈五，周长八十二丈。城之两掖有门，
东曰昭景，西曰衍祥，入门有蹬道。这里就是团城的昭景门。门口有几
个人在扫地。
LONG
	);
	set("exits", ([
		"west"      : __DIR__"chengguang",
		"north"     : __DIR__"yonganqiao",
		"northeast" : __DIR__"qianmen",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
