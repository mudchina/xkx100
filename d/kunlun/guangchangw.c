// Room: /d/kunlun/guangchangw.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "广场西");
	set("long",@long
这里是一个平平开阔的大广场，广场上有昆仑派的弟子在习武，东
面是仍然是广场，西面过去就是悬崖了，南面是下山的路。
long);
	set("exits",([
		"southeast" : __DIR__"shanlu04",
		"east"      : __DIR__"guangchang",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/zhanchun" :  1,
		__DIR__"npc/kl-dizi3" :  1,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -120000);
	set("coor/y", 40040);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}