// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "走廊尽头");
	set("long", @LONG
你来到走廊的尽头，往北看去是好大的一个湖泊，前面有个
小亭，温氏兄弟还真会享受。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
            "north"     : __DIR__"tingzi",
            "southeast" : __DIR__"zoulang7",
            "south"     : __DIR__"houyuan",
            "southwest" : __DIR__"zoulang3",
	]));
	set("coor/x", 1610);
	set("coor/y", -1910);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}