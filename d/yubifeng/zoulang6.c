// /yubifeng/zoulang6.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long",@LONG
这是一条长长的走廊，通向各个客人的寝室。两侧木壁上或刻有花
鸟鱼虫，或挂了些许时人的字画，每隔七八步，就有一处香台，缕缕青
烟从铜鹤嘴里游出，闻之精神一振。
LONG);
	set("exits", ([
		"east"  : __DIR__"eastroom2",
		"west"  : __DIR__"houting",
		"south" : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6130);
	set("coor/y", 5200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

