// Room: /d/yanziwu/weichang.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "绿围场");
	set("long", @LONG
这里是慕容世家围猎之处。围场不大，但林深草茂，小兽很多。秋
来春往，南来北去的候鸟正当时令，前来凑趣，来考究主人们的箭头是
否锋锐。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"south" : __DIR__"xuanshuan",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 1,
		"/d/hangzhou/npc/maque" : 1,
	]));
	set("coor/x", 830);
	set("coor/y", -1240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

