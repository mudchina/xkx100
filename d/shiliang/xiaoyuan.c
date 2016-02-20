// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "小院子");
	set("long", @LONG
这里是个小院子，打扫得甚为整洁，旁边有棵大树，院子内
放了一些扫把等杂物。往北是个不大的客厅。
LONG
	);
	set("outdoors","shiliang");
	set("no_clean_up", 0);
	set("exits", ([ 
            "southwest" : __DIR__"xiaodao1",
            "north" : __DIR__"xiaoting",
	]));
	set("coor/x", 1620);
	set("coor/y", -1780);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}