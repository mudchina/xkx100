// Room: /d/huanggong/baohedian.c

inherit ROOM;

void create()
{
	set("short", "保和殿");
	set("long", @LONG
碉栏玉砌, 金玉堂皇, 这才是皇族气范. 飞檐敞椽, 支撑天地的大
柱正是八部天龙. 这里是紫禁三殿的--保和殿.
    保和的意思是保持事物的协调. 这座建筑的重檐歇山顶式, 是皇帝
举行殿试的场所以及岁末除夕赐宴外藩王公的地方.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"longzongmen",
		"northeast" : __DIR__"jingyunmen",
		"north"     : __DIR__"qianqingmen",
		"south"     : __DIR__"zhonghedian",
		"east"      : __DIR__"yongxiang4",
		"west"      : __DIR__"yongxiang1",
	]));
	set("coor/x", -200);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}