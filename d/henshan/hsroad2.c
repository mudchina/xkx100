// Room: /d/henshan/hsroad2.c 黄土路
// Modified by Java on Feb.14 1998

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"northwest" : __DIR__"hsroad1",
		"southwest" : __DIR__"hsroad3",
		"southeast" : "/d/yanping/gudao1",
		"northeast" : "/d/huangshan/shanmen",
	]));

	set("no_clean_up", 0);
	set("coor/x", 300);
	set("coor/y", -1100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
