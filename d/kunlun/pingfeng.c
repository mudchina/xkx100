// Room: /d/kunlun/pingfeng.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "石屏风");
	set("long",@long
这是一个巨大的屏风，用昆仑山特产的汗白玉雕成，屏风上的图案
是昆仑派的师祖昆仑三圣何足道挑战少林的风姿，英姿挺拔，颇有一派
宗师之象。屏风后面就是昆仑派的前厅了。
long);
	set("exits",([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"qianting",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/first" : 1,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40050);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
