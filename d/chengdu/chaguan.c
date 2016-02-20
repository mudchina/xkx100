// Room: /d/chengdu/chaguan.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "陆羽茶馆");
	set("long", @LONG
这里是成都最有名的茶楼，成都的达官显贵非常喜欢来的一个地方。
因为这里环境舒适，而且往来的都是有身份有名气的人，在这里你可以
一边品茗，一边同高雅之士高谈阔论。一楼是一般有钱人喝茶的地方，
二楼才是那些真正有身份有文化的雅士饮茶的地方。
LONG
	);
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"chunxilu1",
		"up" : __DIR__"chaguan2",
	]));
	set("objects", ([
		__DIR__"npc/boss" : 1,
	]));
	set("coor/x", -8050);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


