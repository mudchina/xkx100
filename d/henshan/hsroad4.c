// Room: /d/henshan/hsroad4.c 黄土路
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。东面不远
就是衡阳县城了。往西是另外一条大道。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"east"  : __DIR__"hengyang1",
		"west"  : __DIR__"hsroad5",
	]));

	set("no_clean_up", 0);
	set("coor/x", -410);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}