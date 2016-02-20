// Room: /d/chengdu/fengyuting.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "风雨亭");
	set("long", @LONG
你站在亭里，看着亭外灰蒙蒙的天，不禁有一种“山雨欲来风满楼”
的感觉。向西望是层起彼伏的街道，行人来来往往。向东望是山麓，郁
郁葱葱的树林中露出了一角飞掾。远处传来了肃穆庄重的钟声，你的灵
台一片清明。
LONG	);

	set("exits", ([
		"south" : __DIR__"gongqiao1",
	]));
	set("objects", ([
	    __DIR__"npc/youke" : 2,
	]));
	set("coor/x", -8020);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

