// Room: /d/taohua/hill1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "山脊");
	set("long", @LONG
山势至此一转，折而向北就可抵达山顶。往远处望，一片桃花郁郁
葱葱，另一边则可远眺大海，极目海天交接处，似乎有些帆影，但又似
乎是幻觉。
LONG
	);
	set("exits", ([ 
		"westdown" : __DIR__"hill",
		"northup" : __DIR__"hill2",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 8510);
	set("coor/y", -4690);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}