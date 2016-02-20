// Room: /yangzhou/caibopu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","顾家彩帛铺");
	set("long",@LONG
进入彩帛铺中，只见店内拥挤不堪，数个小二在招呼客人，依旧应
接不暇。店内两边各有几个货架，上面陈列着布匹绸缎。几个客商正在
挑选，边上的店员在给他们介绍。几个姑娘手里拿着一匹花布，在身上
比划着，叽叽喳喳的相互说着，不大理会边上嬉皮笑脸的店员。
LONG );
	set("exits", ([
		"south" : __DIR__"caiyixijie",
	]));
	set("objects", ([
		__DIR__"npc/gubancheng" : 1,
	]));
	set("coor/x", 50);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}