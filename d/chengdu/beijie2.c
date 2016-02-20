// Room: /d/chengdu/beijie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
你走在一条宽阔的青石大道上，街上行人很多，个个衣着鲜明，神
气的很，就是不时传来几句四川特有的脏话，“龟儿子的”，“先人板
板”，不过他们并不一定是在骂人哦，只是口头禅不雅而已！东面是一
家赌场，阵阵喧闹声不断地传进你的耳朵里。西面是一家珠宝店。
LONG	);
	set("outdoors","chengdu");
	set("exits", ([
		"east"  : __DIR__"duchang",
		"west"  : __DIR__"zhubaodian",		
		"north" : __DIR__"beijie1",
		"south" : __DIR__"guangchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

 
