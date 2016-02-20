// Room: /d/huangshan/qingliang.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "清凉台");
	set("long", @LONG
这乃黄山观日出的所在，每天清晨，当人登上三面凌空的危岩向北
海远眺，只见“白云倒海忽平铺，点点螺髻时有无”，巍峨的群峰大都
淹没在云海之中。接着天际的鱼肚白变成了五彩瑰丽的朝霞，云层中射
出的红光越来越亮，直到那轮火球冲破云海，腾空而出。久久地让人回
味。
LONG
	);
	set("exits", ([ 
		"northwest" : __DIR__"diezhang",
		"northeast" : __DIR__"feilong",
		"southup"   : __DIR__"shizi",
		"westup"    : __DIR__"qingliangf",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
