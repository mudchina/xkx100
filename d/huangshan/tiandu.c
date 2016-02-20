// Room: /d/huangshan/tiandu.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "天都峰");
	set("long", @LONG
天都是三大主峰中最为险峻的一座，古称“群仙所都”，意为天上
都会。现在路边已有依山凿就的石级和铁索围护的登山道，但是仍然令
人有“难于上青天”之感。途中有一石屏风，刻有“天上玉屏”四字，
由此处远望，浮云怪峰，山泉松海，尽收眼底。
LONG
	);
	set("exits", ([ 
		"westdown"  : __DIR__"jiyu",
		"northdown" : __DIR__"yixian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
