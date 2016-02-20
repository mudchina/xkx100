// Room: /d/wuxi/road3.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
这里已经进入了苏州府管辖的地界了，驿道直直地向东西方延伸
开去。路旁是十分精神的的杨柳树。路上来来去去的，好象是做生意
的商人小贩不少。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"road4",
		"west"  : __DIR__"road2",
	]));
	set("coor/x", 700);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}