// /kaifeng/zhulin1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "小茅屋");
	set("long", @LONG
你走进竹林中的小茅屋，打量了一下，在茅屋仅是用茅草覆顶，四
边的墙壁是用一根根大毛竹打入地下而成的，屋中的桌椅也都是翠竹所
制，桌上放的茶壶是用整个竹根雕成的。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"zhulin0",
	]));

	setup();
	replace_program(ROOM);
}
