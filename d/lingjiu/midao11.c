// midao11.c
//
inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你走着走着，突然发现你迷失了方向，你往回走的时候却发现那已
不是你来的道路了，你不禁心中一阵发麻。突然你在昏黄的灯光下，隐
约发现两边的汉白玉墙壁上刻着一些奇形怪状的符号(fuhao)。
LONG );
	set("exits", ([
		"south" : __DIR__"midao13",
		"north" : __DIR__"midao12",
		"east" : __DIR__"midao14",
		"west" : __DIR__"mishi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50900);
	set("coor/y", 30180);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}