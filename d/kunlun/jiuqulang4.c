// Room: /d/kunlun/jiuqulang4.c
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "九曲廊");
	set("long",@long
九曲廊前后共有九进，曲曲折折地盘旋在水面。一路穿花度柳，抚
石依泉，落花浮荡，水色溶溶。两边垂柳杂着桃杏，藤蔓绕柱。白石为
栏，飞楼插空，转折处皆由小亭相接。
long);
	set("exits",([
		"northeast" : __DIR__"liangong",
		"south"     : __DIR__"jiuqulang3",
		"west"      : __DIR__"jiuqulang5",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -119980);
	set("coor/y", 40110);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}