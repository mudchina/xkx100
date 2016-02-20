// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "走廊");
	set("long", @LONG
你走在一条长长的走廊上，上面雕梁画柱，飞檐琉璃，穿行其
间，心情舒畅。往东是间书房，往西是后院。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
            "southwest" : __DIR__"houyuan",
            "northwest" : __DIR__"zoulang4",
            "south"     : __DIR__"zoulang6",
            "east"      : __DIR__"shufang",
	]));
	set("coor/x", 1620);
	set("coor/y", -1920);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}