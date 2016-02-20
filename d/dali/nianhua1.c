//Room: /d/dali/nianhua1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","拈花后院");
	set("long",@LONG
你举步入寺，只听得叮叮两声清磬，悠悠从后院传出，霎时之间，
只感遍体清凉，意静神闲。你踏实着寺院中落叶，走进后院。你站在
庭中，眼见庭中一株公孙树上一片黄叶缓缓飞落，俗念全消。
LONG);
	set("outdoors", "daliw");
	set("no_clean_up", 0);
	set("exits",([ /* sizeof() == 1 */
	    "out"  : __DIR__"nianhuasi",
	]));
	set("coor/x", -60000);
	set("coor/y", -68990);
	set("coor/z", 20);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/nh1",1);
	}
}