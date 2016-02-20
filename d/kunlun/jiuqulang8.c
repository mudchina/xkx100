// Room: /d/kunlun/jiuqulang8.c
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
		"north" : __DIR__"jiuqulang7",
		"east" : __DIR__"jiuqulang1",
		"southwest" : __DIR__"nanwoshi",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -120000);
	set("coor/y", 40090);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "southwest" && me->query("gender") != "男性")
		return notify_fail("你低着头走了进去。却发现里面是男卧室，不由得脸上发烧，一扭头跑了出来。\n");
	return ::valid_leave(me, dir);
}