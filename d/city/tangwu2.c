// Room: /d/city/tangwu2.c
// Last Modified by winder on Jul. 20 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","堂屋");
	set("long",@LONG
北墙贴着一张孔子画像，下面点着一柱清香。东边倚墙放着一书架，
稀稀拉拉放着几本书。中间放着几张木桌和凳子，却没有一个学童在屋
里，只有一个老儒生在边上坐着拿本书在独自读着，边上摆着一把戒尺
(chi)。
LONG
	);
	set("exits",([ /* sizeof() ==  */
		"south" : __DIR__"zizheng",
	]));
	set("objects", ([ /* sizeof() == */
		__DIR__"npc/wuguxian" : 1,
	]));
	set("item_desc" , ([ /* sizeof() == */
		"chi" : "戒尺上落满了灰尘，象是许久未用了。\n",
	]));
	set("coor/x", -30);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
