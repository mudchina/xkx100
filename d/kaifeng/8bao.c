// /kaifeng/8bao.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "八宝琉璃殿");
	set("long", @LONG
这座大殿相对于大雄殿来说要小得多，但却是显得富丽精致无比，
大殿的檐面是用琉璃瓦铺的，四面的墙壁上都镂刻了佛经故事，正中的
弥勒佛像用黄金，翡翠，宝石，珍珠等装饰称八宝佛像。
LONG);
	set("objects", ([
		__DIR__"npc/jiansi" : 1,
		__DIR__"npc/obj/milexiang" : 1,
	]));
	set("exits", ([
		"south"     : __DIR__"houyuan",
		"northdown" : __DIR__"gongmen",
	]));

	setup();
	replace_program(ROOM);
}
