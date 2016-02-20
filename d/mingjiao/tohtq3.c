//TOHTQ3.C

inherit ROOM;

void create()
{
	set("short", "山谷路");
	set("long", @LONG
山路掩在土层下，前面似乎没有路了。满山树林密集，鸦鸟群集，
林中烟雾飘荡，不知所之。
LONG );
	set("exits", ([
		"southup" :__DIR__"tohtq2",
		"enter"   :__DIR__"tohtq4",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52040);
	set("coor/y", 890);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}