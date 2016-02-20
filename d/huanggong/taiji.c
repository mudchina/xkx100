// Room: /d/huanggong/taiji.c

inherit ROOM;

void create()
{
	set("short", "台基");
	set("long", @LONG
这个巨大的台基建在皇城的中轴线上, 有三层台阶, 中间是铺了地
毯的御道. 东西两侧各是一个日晷(gui)和一个嘉量(liang). 四周围都
是汉白玉雕刻栏板, 景象无比壮观. 三层台基每层都呈须弥座形, 四周
汉白玉栏杆环绕, 栏杆上共有一千四百五十八根望柱.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"taihedian",
	]));
	set("objects", ([
		__DIR__"npc/suke" :1,
	]));
        set("no_clean_up", 0);
	set("item_desc", ([
		"gui"   : "这原是时间的标准量器, 是皇帝受命于天的象征.\n",
		"liang" : "这原是容积的标准量器, 是皇帝公正无私和至高无上的象征.\n",
	]));
	set("coor/x", -200);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}