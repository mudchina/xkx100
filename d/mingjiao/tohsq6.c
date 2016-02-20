//TOHSQ6.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
一挂巨大的瀑布白龙出霄般横越山间，水气已浓得仿佛可以滴下水
珠儿来。山峦间升起薄薄的青雾，凝聚不散。哗哗的水声震耳欲聋。
LONG );
	set("exits", ([
		"north" : __DIR__"tohsq7",
		"south" : __DIR__"tohsq5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52020);
	set("coor/y", 910);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}