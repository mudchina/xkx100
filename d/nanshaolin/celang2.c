// Room: /d/nanshaolin/celang2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "东禅房侧廊");
	set("long", @LONG
这里是禅房侧廊。彩梁画栋，连顶棚也用彩漆绘满了各种飞天的图
形，出自名家手笔，端的壮丽不凡。北望是一片槐树林，鸟语花香隐隐
传来令人心旷神怡。东面是僧人们休息用的僧舍。   
LONG );
	set("exits", ([
		"northeast" : __DIR__"songshu3",
		"south"     : __DIR__"stoneroad3",
		"east"      : __DIR__"sengshe1",   
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1810);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

