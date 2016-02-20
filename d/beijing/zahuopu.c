inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一家杂货铺，大箱小箱堆满了一地，都是一些日常用品。胡掌
柜懒洋洋地躺在一只躺椅上，招呼着过往行人。据说私底下他也卖一些
贵重的东西。摊上立着一块招牌(zhaopai)。
LONG );
	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
	set("exits", ([
		"east" : __DIR__"xidan",
	]));
	set("objects", ([
		__DIR__"npc/hu": 1,
	]));
	set("coor/x", -230);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
