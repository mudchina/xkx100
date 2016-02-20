// Room: /d/kunlun/qishi.c
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
inherit ROOM;

void create ()
{
	set("short", "棋室");
	set("long", @LONG
昆仑三圣以“琴”、“棋”、“剑”著称，奕棋是每个昆仑弟子入
门必修的功课。此处是昆仑派的棋室，供昆仑弟子磨练棋艺使用。
LONG );
	set("exits",([
		"west" : __DIR__"jiashan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119970);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}