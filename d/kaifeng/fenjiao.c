// /kaifeng/fenjiao.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "粪窖");
	set("long", @LONG
一股臭味扑鼻而来，一堆金头苍蝇围着个小池子不断打转，这是个
方便僧人用来浇灌菜地的小粪池子，自然是比较不好闻你还是赶快走开
些吧，不小心会掉下去的。
LONG);
	set("objects", ([
		__DIR__"npc/popi" : 1,
		__DIR__"npc/wulai" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"maofang",
		"north" : __DIR__"kongdi",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
