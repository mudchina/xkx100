// /kaifeng/longting.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "龙亭大殿");
	set("long", @LONG
龙亭大殿原先是帝王行宫，后宋亡之后，宫殿颓废，后人在此地复
建大殿，殿内珍宝林陈高檐直柱，令人叹为观止。集南北宫殿建筑之大
成。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"tingyuan",
	]));

	setup();
	replace_program(ROOM);
}
