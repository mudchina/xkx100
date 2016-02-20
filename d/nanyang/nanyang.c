// Room: /d/nanyang/nanyang.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("short", "南阳城");
	set("long", @LONG
这里便是当年诸葛先生的故居。南阳城虽不大，因为地出要冲，南
来北往的客人特别多，所以也五脏俱全，酒楼，客栈，马店，满城子都
是。本地人口甚少，到处都是行色匆匆的江湖客人。
LONG );
	set("exits", ([
		"south" : __DIR__"dajie1",
		"north" : __DIR__"dajie2",
		"east"  : __DIR__"kedian1",
		"west"  : __DIR__"jiulou1",
	]));
	set("objects",([
		"/d/shaolin/npc/xiao-fan" : 1,
	]));
	set("outdoors", "nanyang");
	set("coor/x", 10);
	set("coor/y", 500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
