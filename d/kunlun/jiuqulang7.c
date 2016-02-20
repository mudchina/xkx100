// Room: /d/kunlun/jiuqulang7.c
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
		"west"   : __DIR__"chufang",
		"east"   : __DIR__"sanshengtang",
		"north"  : __DIR__"jiuqulang6",
		"south"  : __DIR__"jiuqulang8",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -120000);
	set("coor/y", 40100);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}