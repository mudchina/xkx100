// /kaifeng/dadao0.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set ("short", "大道");
	set ("long", @LONG
在平原之上的一条大路，来往人很多，路边相隔不远就有个小亭子
供行人歇脚，向北去就是开封城。南面不远是个三叉路口。
LONG);
	set("outdoors", "kaifeng");

	set("exits", ([
		"south" : __DIR__"dadao1",
		"north" : __DIR__"nanying",
	]));

	setup();
	replace_program(ROOM);
}
