// Room: /yangzhou/changtichunliu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "春柳亭");
	set("long", @LONG
长堤中段临湖筑一个半岸半水、置美人靠的木构件方亭。亭内悬“
长堤春柳”匾，仍为清光绪道员陈重庆手笔。外悬“中流自在”匾，两
柱悬挂王板哉手书楹联(lian)，乃集赵孟兆页、元好问句而成。
LONG );
	set("outdoors", "shouxihu");
	set("no_clean_up", 0);
	set("item_desc", ([
		"lian" : "
        佳        宿
        气        云
        溢        澹
        芳        野
        甸        川\n",
	]));

	set("exits", ([
		"south" : __DIR__"changdi1",
		"north" : __DIR__"changdi2",
	]));
	set("coor/x", 0);
	set("coor/y", 32);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}