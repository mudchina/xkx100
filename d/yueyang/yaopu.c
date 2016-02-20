// Room: /d/yueyang/yaopu.c
// Last Modifyed by Winder on Dec. 4 2001
inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息。柜台后面是一个大
药柜，密密麻麻的的几百个小抽屉里你也懒得数了。柜台后站在一名小
伙计，一双贼兮兮的眼睛不时扫过你的腰部。
    柜上立着一块招牌(zhaopai)。
LONG );
	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 购物。\n",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"beijie",
	]));
	set("coor/x", -1420);
	set("coor/y", -2260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
