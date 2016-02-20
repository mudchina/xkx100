// Room: /d/kunlun/qinshi.c
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
inherit ROOM;

void create ()
{
	set("short", "琴室");
	set("long", @LONG
昆仑三圣以“琴”、“棋”、“剑”著称，奕棋是每个昆仑弟子入
门必修的功课。此处是昆仑派的琴室，供昆仑弟子磨练琴艺使用。
LONG);
	set("exits",([
		"east" : __DIR__"liangting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -120010);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}