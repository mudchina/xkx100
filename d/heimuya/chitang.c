// Room: /d/heimuya/chitang.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","池塘");
	set("long",@LONG
这是一个小池塘，池塘里有数对鸳鸯悠游其间，池边还有几只白鹤
在觅食。
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"north" : __DIR__"baihutang",
		"west"  : __DIR__"shenggu",
		"east"  :__DIR__"chufang2",
	]));
	set("objects",([
		"/d/dali/npc/xianhe" : 1 + random(3),
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 3990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}