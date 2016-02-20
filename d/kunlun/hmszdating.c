// Room: /d/kunlun/hmszdating.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"山庄大厅"NOR);
	set("long", @LONG
这里是山庄会客之所，大厅之中坐着此间庄主。每逢年节，就有许
多仆在此等侯，希望主人能赏一些银子。厅子两旁放置着许多椅子和茶
机，是供客人座的。这里虽然远离中原，但来此之客却是当真不少。厅
中壁上挂着一大副猛虎之图。这里有几个童仆来回的侍侯着。
LONG	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"hmszhuang",
		"north" : __DIR__"hmsznuange",
		"east"  : __DIR__"hmszhouyuan",
	]));
	set("objects",([
		__DIR__"npc/zhu"  :  1,
	]));
	set("coor/x", -90030);
	set("coor/y", 10020);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
