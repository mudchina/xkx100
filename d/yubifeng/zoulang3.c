// /yubifeng/zoulang3.c
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
		"west"  : __DIR__"westroom1",
		"north" : __DIR__"zoulang5",
		"south" : __DIR__"zoulang1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6110);
	set("coor/y", 5190);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
