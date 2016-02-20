// Room: /d/huangshan/yixian.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "一线天");
	set("long", @LONG
天都下来，越磴道往文殊院去，经小心坡，蒲团松，便达沿垂直裂
系风化的“一线天”。这里十分狭长，高达三十余米的石壁紧紧夹峙最
宽处不过两米，窄处只有半米，仰望长空，蓝天一线。一线天西北便是
文殊院了。
LONG
	);
	set("exits", ([ 
		"west"    : __DIR__"wenzhu",
		"southup" : __DIR__"tiandu",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
