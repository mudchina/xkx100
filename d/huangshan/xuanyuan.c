// Room: /d/huangshan/xuanyuan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "轩辕峰");
	set("long", @LONG
这是黄山后山东的最高峰，因一路怪石嶙峋，加之前面采石峰异常
难行，所以很少人烟。据说这里便是黄帝得道飞升的所在，也不知真假
但是至今留有许多道家遗迹，可见确有人在此修道。
LONG
// 南边有一矮峰，上面居然隐约有一茅庐，似乎有人居住，两峰之间仅有一根铁索。
	);
	set("exits", ([ 
		"west" : __DIR__"caishi",
//		"east" : __DIR__"tiesuo",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
