// Room: /d/jiaxing/nanhu.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖");
	set("long", @LONG
这里是嘉兴南湖。节近中秋，荷叶渐残，莲肉饱实。一阵轻柔婉转
的歌声，飘在烟水蒙蒙的湖面上。湖边有一个道姑在一排柳树下悄立已
久。
LONG );
	set("exits", ([
		"west"      : __DIR__"jiaxing",
		"east"      : __DIR__"jiaxinggang",
		"south"     : __DIR__"tieqiang",
		"north"     : __DIR__"diaoyu",
		"southeast" : __DIR__"nanhu1",
	]));
	set("outdoors", "jiaxing");
	set("objects", ([
		CLASS_D("gumu")+"/limochou" : 1,
		"/clone/medicine/vegetable/baizhi" : random(2),
	]));
	set("coor/x", 1510);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
