// /d/xingxiu/mogaoku.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "莫高窟");
	set("long", @LONG
这里墙壁上绘制着与佛教相关的画面，有仙女飞天，还有反弹琵琶。
洞中还有很多佛像和经书。你被这些瑰丽的文化之宝惊呆了。
LONG );
	set("exits", ([ 
	     "out" : __DIR__"yueerquan",
	]));
	set("objects", ([ 
		"/d/shaolin/obj/fojing1"+random(2) : random(2),
		"/d/shaolin/obj/fojing2"+random(2) : random(2),
	]));
	set("coor/x", -20310);
	set("coor/y", 170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

