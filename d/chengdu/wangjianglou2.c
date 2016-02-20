// Room: /d/chengdu/wangjianglou2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "望江楼二楼");
	set("long",@LONG
你来到望江楼上，极目远眺，整个成都的美景尽收眼低。只见府南
河象条玉带似的环绕全城，太阳照在河面，发出缎子般的光泽。旁边的
竹林郁郁葱葱，空气竟也变得更加清新起来。楼的墙上刻着前代文人墨
客留下的诗句。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"down" : __DIR__"wangjianglou1",
	]));
	set("objects", ([
		__DIR__"npc/youke" : 2,
	]));
	set("coor/x", -8030);
	set("coor/y", -3030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);       
}


