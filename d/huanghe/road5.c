// Room: /d/heimuya/road5.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条黄土路上。这里已经是陕西地面了，向南走是一条黄土
大道，两边望不尽的黄土高坡，没有一丝吝啬的绿色。东北隐隐传来流
水的声响。
LONG );
	set("outdoors", "heimuya");
	set("exits", ([
		"northeast" : __DIR__"weifen",
		"south"     : __DIR__"road6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1010);
	set("coor/y", 690);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}