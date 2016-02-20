// Room: /yangzhou/tianwangdian.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","天王殿");
	set("long",@LONG
山门内为天王殿，面南正中，五架梁。中设佛龛，端坐弥勒佛，龛
前有楹联(lian)。背立护法韦陀。两厢列彩塑四大天王：东厢立东方持
国天王、南方增长天王，西厢立西方广目天王、北方多闻天王。
LONG );
	set("item_desc", ([
		"lian" : "
        大腹能容容天下难容之事

        慈颜常笑笑世间可笑之人
\n"
	]));
	set("objects", ([
		"/d/hangzhou/npc/shami" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"yongdao",
		"south" : __DIR__"shanmen",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}