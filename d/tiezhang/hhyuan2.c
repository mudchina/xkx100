// Room: /d/tiezhang/hhyuan2.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"花圃"NOR);
	set("long", @LONG
只见这里摆满了茉莉、素馨、麝香藤、朱槿、玉桂、红蕉，都是夏
日盛开的香花。院墙上又挂了枷木兰、真腊龙诞等香珠，但觉馨意袭人， 
清芬满园。园中桌上放着几盆新藕、甜瓜、枇杷、等鲜果，椅子上丢着
一把蒲扇，看来是帮主休息的地方。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"hhyuan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2030);
	set("coor/y", -1940);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}