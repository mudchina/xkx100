// Room: /yangzhou/caiyijiekou.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","彩衣街口");
	set("long",@LONG
一过小秦淮河，你便感到一种不同的气氛。河的东岸是新城，多为
商贾。你只见街口到处是店铺，临街而设，各自挑着高高的旗帜。小贩
沿街叫卖，喧嚣吵闹。往北是天宁巷，通向天宁寺。往东就是彩衣街，
扬州的绸缎衣帽店大多在此。南面北柳巷是淮扬烟花之地。
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"west"  : __DIR__"kaimingqiao",
		"east"  : __DIR__"caiyixijie",
		"north" : __DIR__"tianningxiang",
		"south" : __DIR__"beiliuxiang",
	]));
	set("objects", ([
		__DIR__"npc/geji" : 1,
	]));
	set("coor/x", 40);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}