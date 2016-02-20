// Room: /d/henshan/hsroad1.c 黄土路
// Modified By Java Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里向北通往
扬州，往南就进入湖南地界了。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"northdown" : "/d/wudang/wdroad4",
		"southeast" : __DIR__"hsroad2",
	]));

	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -1000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
