// Room: /d/chengdu/chunxilu2.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIY "春熙路" NOR);
	set("long", @LONG
你走在一条热闹的大道上，街上人群熙熙攘攘，可得当心小偷哦。
东面是个打铁铺子，西面有个钱庄，西南方有条青石巷。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"chunxilu3",
		"north" : __DIR__"chunxilu1",
		"east"  : __DIR__"datiepu",
		"west"  : __DIR__"qianzhuang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}

