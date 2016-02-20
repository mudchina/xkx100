// Room: /d/kunlun/keting1.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "客餐厅");
	set("long",@long
这里是待客餐厅，里面简单，只有一些椅子和桌子，桌子上摆着些
茶和点心供客人食用。不少江湖人士不远千里来到这里，往往先到这里
歇息片刻，恢复一下。
long);
	set("exits",([
		"west" : __DIR__"elang02",
	]));
	set("objects",([
		__DIR__"obj/rice" : 2,
		__DIR__"obj/xiangcha" : 1,
	]));
	set("coor/x", -119960);
	set("coor/y", 40060);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}