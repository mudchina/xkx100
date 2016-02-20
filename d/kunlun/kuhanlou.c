// Room: /d/kunlun/kuhanlou.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "苦寒楼");
	set("long",@long
这里是昆仑派的苦寒楼，取名自“梅花香自苦寒来”之意，乃是昆
仑派前辈为了激励后进昆仑派弟子而建的，是昆仑弟子静修之所。
long);
	set("exits",([
		"north" : __DIR__"shanlin"+(random(5)+1),
		"enter" : __DIR__"kuhanlou1",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119900);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}