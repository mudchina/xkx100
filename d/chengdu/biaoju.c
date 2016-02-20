// Room: /d/chengdu/biaoju.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "威武镖局");
	set("long", @LONG
门前两个威武的石狮子，四间开的大红门，边上是大红灯笼高高挂。
不时有几个镖师进进出出，门口是几个看守门户的镖师，个个看上去体
格魁梧，手底下很有些功夫的样子，大门正中是块金匾，上书『威武镖
局』四个金字。这里就是远近闻名的威武镖局成都分号了。
LONG	);
	set("exits", ([
		"east" : __DIR__"beijie",
	]));
	set("objects", ([
		__DIR__"npc/biaotou" : 2,
	]));
	set("coor/x", -8060);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

