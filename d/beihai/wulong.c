// /d/beihai/wulong.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "五龙亭");
	set("long", @LONG
这里是阐福寺前之五龙亭，亭子伸入水中，五亭俱为方形，前后错
落布置。中亭名龙泽，重檐下方上恩赐，左面澄祥亭为重檐，滋香亭为
单檐；右面涌瑞亭，浮翠亭与左面相同。五亭皆绿琉璃瓦顶，黄瓦剪边，
檐下梁枋施小点金旋子彩画，绚丽多彩。
LONG
	);
	set("exits", ([
		"west" : __DIR__"xiaolu2",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
