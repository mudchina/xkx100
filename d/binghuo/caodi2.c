// Room: /binghuo/caodi1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
一片平缓的草地一直沿岸延伸，间或有些许岩石露出地面，挺立
浪头，忍受海潮千年来不尽的冲刷。一些叫不出名目的大鸟小兽在草
丛中出没，十分自在地游嬉。西北望去，远远可以看到高高的火山口
正在喷烟吐火。
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest"  : __DIR__"caodi1",
		"northwest"  : __DIR__"yuanye1",
	]));
	setup();
	replace_program(ROOM);
}

