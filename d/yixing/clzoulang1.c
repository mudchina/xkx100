// /d/yixing/clzoulang1.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
宽敞的走廊人来人往，再向内便是总舵的内宅了。西面是间干杂活
的柴房，向东有个小小的亭子。一些日常守卫的帮众警惕地注视着每个
人。
LONG );
	set("exits", ([
		"west"  : __DIR__"clchaifang",
		"east"  : __DIR__"clbajiaoting",
		"south" : __DIR__"cldating",
		"north" : __DIR__"clzoulang2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yixing");
	setup();

	replace_program(ROOM);
}

