// Room: /d/kunlun/shanmen.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "昆仑派山门");
	set("long",@long
你一路走来，饱受大风黄沙之苦，渐渐树木多了起来，不时可听见
枝叶中传来的鸟鸣，路边草丛偶尔也能发现一些开着的野花。到得这里，
已是绿树红花，十分茂盛，你万万没想到深山中却有如此所在，精神大
为一振。前面是一座山门，写着“昆仑派”三个大字。
long);
	set("exits",([
		"eastup"    : __DIR__"shanlu01",
		"southdown" : __DIR__"klshanlu",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/jiangtao" : 1,
		__DIR__"npc/kl-dizi1" :  1,
		__DIR__"npc/kl-dizi2" :  1,
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -120000);
	set("coor/y", 35000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
