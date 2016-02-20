// Room: /city/biaojucf.c

inherit ROOM;

void create()
{
	set("short", "镖局厨房");
	set("long", @LONG
福威镖局对伙计们十分款待，不但每月有薪金，而且还包吃住。这
里就是伙计们一日三餐的地方。厨房的墙上挂满了锅碗瓢盆，还有一些
风干的卤味儿。房中放着一张长台，长台的周围摆着几条长凳。
LONG
        );
	set("exits", ([
		"south" : __DIR__"biaojuhy",
	]));
	set("objects", ([
		__DIR__"npc/hua" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6295);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
