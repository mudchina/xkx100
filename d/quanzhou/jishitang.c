// Room: /d/quanzhou/jishitang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "济世堂老店");
	set("long", @LONG
这是间老字号的中药铺，屋里弥漫着浓厚的药味。正前方有一个红
漆柜台，柜台后是一个硕大无比的药柜，几乎盖住了整堵墙，柜子上有
无数的盛药的小抽屉，每个抽屉均标了小字，注明药物名称。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"east"    : __DIR__"yaofang",
		"enter"   : __DIR__"neitang",
		"north"   : __DIR__"westroad2",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
