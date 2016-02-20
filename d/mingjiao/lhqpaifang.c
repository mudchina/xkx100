//LHQPAIFANG.C

inherit ROOM;

void create()
{
	set("short", "烈火旗牌坊");
	set("long", @LONG
这里是昆仑山南麓的一片开阔地，四周山崖环抱，青木遮天，正对
路中的是一座大红牌坊。穿过牌坊，是一片红砖红瓦，遍插镶红团龙旗，
路边齐齐站立两排教众，整个山谷中好似烈焰蒸腾，红雾遍野，实在是
江湖中一般门派所没有的壮观景象。由此向东北折转，大路直通锐金旗；
由此向西北而行，则为巨木旗。三旗承犄角鼎立之势，以巩固明教外围。
LONG );
	set("exits", ([
		"northeast" : __DIR__"torjq1",
		"northwest" :__DIR__"tojmq1",
		"northup"   : __DIR__"lhqmen",
		"southdown" : __DIR__"shanlu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52030);
	set("coor/y", 830);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}