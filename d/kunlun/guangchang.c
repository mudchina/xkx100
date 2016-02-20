// Room: /d/kunlun/guangchang.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "大广场");
	set("long",@long
这里是一个平平开阔的大广场，广场上有昆仑派的弟子在习武，前
面不远处是个巨大的石屏风，后面就是昆仑派的前厅了，西面和东面仍
然是广场。
long);
	set("exits",([
		"south" : __DIR__"shanlu04",
		"north" : __DIR__"pingfeng",
		"west"  : __DIR__"guangchangw",
		"east"  : __DIR__"guangchange",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/gaozecheng" :  1,
		__DIR__"npc/kl-dizi2" :  2,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40040);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}