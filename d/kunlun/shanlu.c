// Room: /d/kunlun/shanlu.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "西域山路");
	set("long",@long
渐行渐西，天气一天冷似一天，西域昆仑派势力雄强，沿途倒并无
什么强盗，只是黄沙扑面，寒风透骨，却也着实难熬。
long);
	set("exits",([
		"west" : __DIR__"shanlu1",
		"east" : __DIR__"zhenyuanqiao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -70000);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}