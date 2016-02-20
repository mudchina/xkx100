// Room: /d/yueyang/zahuopu.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一家小小的杂货铺，好象生意蛮好的样子，货物不少，堆得也
乱，老板显然没时间整理这个小小店面。这不，你一进来，他就迎了上
来。
    墙上贴着一块招牌(zhaopai)。
LONG );
	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
	set("exits", ([
		"west" : __DIR__"beijie",
	]));
	set("objects", ([
		__DIR__"npc/laoban": 1,
	]));
	set("coor/x", -1400);
	set("coor/y", -2260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
