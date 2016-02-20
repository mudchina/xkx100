//  Room:  /d/lanzhou/cuiying.c

inherit  ROOM;

void  create  ()
{
	set("short",  "翠英门");
	set("long",  @LONG
你走在大街上，踩着坚实的青石板地面。迎面一座牌坊，上书“翠
英门”三个大字，书法龙飞凤舞，想必为名家所提。虽东边有庙会，可
这里却还是相当幽雅恬静，南边不时传来朗朗书声。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"street3",
		"south" : __DIR__"zhigong",
		"east"  : __DIR__"square",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9300);
	set("coor/y", 2690);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}