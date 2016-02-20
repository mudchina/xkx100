//Room: /d/dali/nongtian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","农田");
	set("long",@LONG
一小片在山坡下的竹林里开垦出来的农田，临有溪流，种植着水
稻。台夷生活很大程度上依靠农业，从事农业的却基本上是妇女。男
子大都专司狩猎和捕鱼。
LONG);
	set("objects", ([
	   __DIR__"npc/nongfu1": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"wuding",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41010);
	set("coor/y", -79020);
	set("coor/z", 0);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/nt1",1);
	}
}