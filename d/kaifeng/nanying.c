// /kaifeng/nanying.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "南盈门");
	set("long", @LONG
南盈门是开封城的南门，由于开封府尹治理有方，开封境内很是平
安。出城不远就是禹王台。
LONG);
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
		__DIR__"npc/walker" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"jiedao2",
		"south" : __DIR__"dadao0",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
