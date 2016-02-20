// Room: /d/henshan/hsroad3.c 黄土路
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。西面不远
就是衡阳县城了。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"northeast": __DIR__"hsroad2",
		"west"     : __DIR__"hengyang",
	]));

	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}