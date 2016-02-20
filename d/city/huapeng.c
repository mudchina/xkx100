// Room: /city/huapeng.c

inherit ROOM;

void create()
{
	set("short", "花棚");
	set("long", @LONG
这是在芍药圃正中用不去皮的松树搭成的一座花棚，树上的树叶依
旧，棚内椅座乃是用天然树石，四周种满花木青草，再以段段竹节引水，
流转棚周，淙淙有声。在此饮酒赏花真是意境无穷。
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"west"       : __DIR__"chanzhimenqian",
	]));
	set("coor/x", -19);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}