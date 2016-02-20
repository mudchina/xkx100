// Room: /d/heimuya/basket.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "竹篓");
	set("long", @LONG
这是一只大竹篓，足可装得十来石米。抬头上望，只见头顶有天风
崖壁，这黑木崖着实高得厉害。
LONG );
	set("outdoors", "heimuya");
	set("no_clean_up", 0);
	set("coor/x", -3261);
	set("coor/y", 4200);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}