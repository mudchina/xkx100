// Room: /d/wuyi/huanguyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "换骨岩");
	set("long", @LONG
换骨岩在幔亭峰之北，相传是武夷十三仙在次换骨成仙。于是，这
里就成了人间和仙界的分水岭。岩上灵云洞中七股泉水交相流淌，称为
七星泉。云虚洞内宽达数丈，内有小楼，不施片瓦，风雨不侵，俗称“
仙女梳妆楼”。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"sangufeng",
		"south"     : __DIR__"mantingfeng",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -4960);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

