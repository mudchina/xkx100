inherit ROOM;

void create()
{
	set("short", "全聚德酒楼");
	set("long", @LONG
方圆数百里内提起全聚德酒楼可以说是无人不知，无人不晓。楼
下布置简易，顾客多是匆匆的行人，买点包子、鸡腿、米酒就赶路去
了。楼上是雅座。
LONG );
	set("exits", ([
		"east" : __DIR__"wangfu2",
		"up"   : __DIR__"jiulou2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	set("coor/x", -190);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
