// Room: /d/kunlun/zhengyuanqiao.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "镇远桥");
	set("long",@long
这座桥号称“天下黄河第一桥”，气势极为雄伟，扼守西域，东往
中原。黄河水从桥底倾泻而过，轰隆作响。
long);
	set("exits",([
		"west"      : __DIR__"shanlu",
		"southeast" : "/d/mingjiao/shanjiao",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" :  1,
		"/d/city/npc/bing" :     3,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -60000);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}