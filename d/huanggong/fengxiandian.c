// Room: /d/huanggong/fengxiandian.c

inherit ROOM;

void create()
{
	set("short", "奉先殿");
	set("long", @LONG
奉先殿是皇宫中至要之所. 殿里供奉着历代皇帝的图像. 一旦有何
重大决策, 皇帝都会亲自来此, 奉告列祖列宗. 擒拿敖拜之策就是在这
里定下的.
LONG
	);
	set("exits", ([
		"south"     : __DIR__"fengxianmen",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5182);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}