// /d/beihai/qianmen.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "前门");
	set("long", @LONG
这里是北海的前门，由于北海是专门供皇宫贵族游乐的地方，所以
一向是禁区，普通老百姓是不可以进去的。门是朱红色的，门楣上挂这
一块匾(bian)，门口站着两个卫士。
LONG
	);
	set("cost", 2);
	set("item_desc", ([
		"bian" : "这是一块黑色的匾，上面用金漆写了四个大字:北海 禁苑\n",
	]));
	set("exits", ([
		"east"      : __DIR__"shulin",
		"southwest" : __DIR__"zhaojing",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
