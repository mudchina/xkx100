// Room: /d/taohua/chufang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是桃花岛的厨房。黄药师不知使用了什么方法抓了几个御厨来，
正在忙碌着。屋中充斥着青菜和调料的味道。几个厨师正在忙碌着。偶
尔会有些吃不完的主食和做菜时剩下的猪肉留在这里。
LONG
	);
	set("no_clean_up", 0);

	set("objects",([
		__DIR__"obj/meat" : 1,
		__DIR__"obj/rice" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"neishi2",
		"south" : __DIR__"fanting",
	]));

	set("coor/x", 8990);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}