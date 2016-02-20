// Room: /city/dongting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "东厅");
	set("long", @LONG
这里是衙门东厅，是知府招待客人的所在。厅中摆着一张杉木圆桌
和几张椅子，桌上是一套精致的宜兴瓷器。墙上挂着一幅中堂，画的是
猛虎下山，乃是知府的手笔。
LONG );
	set("exits", ([
		"west" : __DIR__"zhengtang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -19);
	set("coor/y", 2);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}