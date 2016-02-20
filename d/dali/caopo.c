//Room: /d/dali/wumeng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","村外草坡");
	set("long",@LONG
一大片山坡长满青草，正是放牧牛羊的好地方。这里地势甚高，
天空呈深蓝色，附近山岭树木已经甚少，基本上都是低矮灌木或草地。
不少附近的村民在此放牧。
LONG);
	set("objects",([
	    __DIR__"npc/muyangren": 1,
	    __DIR__"npc/muyangnu": 1,
	]));
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"wumeng",
	]));
	set("coor/x", -42000);
	set("coor/y", -52000);
	set("coor/z", 30);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/cwcp",1);
	}
}