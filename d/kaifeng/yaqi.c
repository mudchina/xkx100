// /kaifeng/yaqi.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "雅琪轩");
	set("long", @LONG
雅琪轩是间出售官瓷的商店，其间也出售些书画精品。你瞧了一下，
店铺中四面木架子上大小各类的瓷器，大多是富贵人家用的。象粗瓷，
粗碗之类东西，只能从地摊买了。
LONG
	);
	set("objects", ([
		__DIR__"npc/liuzhanggui" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"road3",
	]));

	setup();
	replace_program(ROOM);
}
