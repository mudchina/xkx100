// Room: /d/heimuya/changtan.c
// Last Modified by winder on Apr. 10 2000

inherit ROOM;

void create()
{
	set("short", "长滩");
	set("long", @LONG
这是一片长滩，不时有日月教教众乘船往来。滩头插着一面日月教
的旗帜，表明这里是日月神教的地盘，尽管江面上往来的船只很多，但
是并没有船敢在这里停留。岸边正停靠着一尾日月教的小船。
LONG );
	set("exits", ([
		"westup" : __DIR__"shandao1",
		"enter"  : __DIR__"duchuan1",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/huang" : 1,
		__DIR__"npc/heiyiren" : 2,
	]));
	set("outdoors", "heimuya");
	set("coor/x", -3200);
	set("coor/y", 4200);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "enter" ) me->set_temp("hmy_ship/ct", 1);
	else me->delete_temp("hmy_ship");
	return ::valid_leave(me, dir);
}

