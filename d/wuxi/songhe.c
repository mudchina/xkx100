// Room: /d/wuxi/songhe.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "松鹤楼");
	set("long", @LONG
此乃江南四大名楼之一的松鹤楼，正中一块金字招牌迎街而立，招
牌年深月久，被烟熏成一团漆黑，上面的三个金字却依旧闪烁发光。阵
阵酒香肉气从厨房中传出。厨子刀杓声和跑堂吆喝声响成一片，楼下布
置简易，顾客多是匆匆的行人，买点包子、鸡腿、米酒就赶路去了。楼
上是雅座。
LONG );
	set("exits", ([
		"up"    : __DIR__"songhe2",
		"west"  : __DIR__"southroad1",
	]));
	set("objects", ([
			__DIR__"npc/xiaoer2" : 1,
	]));
	set("coor/x", 380);
	set("coor/y", -810);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}