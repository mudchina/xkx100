//Room: /d/dali/biluoxueshan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","碧罗雪山");
	set("long",@LONG
你身处一片大雪山之中，此地只是半山腰，却已经积雪皑皑，寒
风刺骨了。仰头望去，银白的峰尖似在云中，天空也蓝得特别深邃。
由此向上的山颠杳无生命的踪迹，只向下百丈的山腰便是树木苍郁、
飞禽走兽横行的世界了。向东不远有一条大河流过，在崇山峻岭之间
冲击出一片谷地。
LONG);
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "eastdown"   : __DIR__"shanlu2",
	    "westdown"   : __DIR__"lushuieast",
	]));
	set("no_clean_up", 0);
	set("coor/x", -70000);
	set("coor/y", -70000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}