// Room: /d/taiwan/jilonggang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "鸡笼港");
	set("long", @LONG
鸡笼港，自海上遥望，状似鸡笼，而鸡笼港口外的鸡笼屿亦貌如鸡
笼，故汉族移民以鸡笼名之。鸡笼港位于台湾东北部，在台湾海峡的北
口，一面聚连东海和太平洋，以港埠闻名；港湾之东、南、西三面环山，
独有北侧为出海之口；市内有蚵壳港（西南边）、田寮港（东边）骸牛
稠港（西北边）等三条短而浅的小溪，流入港湾。 
LONG );
	set("exits", ([
		"west" : __DIR__"danshui",
	]));
	set("objects", ([
		__DIR__"npc/wokou": 3,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2550);
	set("coor/y", -6970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

