// Room: /d/taishan/dongling1.c
// Last Modified by Winder on Aug. 25 2001

inherit RESTROOM_IN;

void create()
{
	set("short", "东灵后殿");
	set("long", @LONG
LONG );

	set("sleep_room", 1);
	set("no_clean_up", 0);
	set("no_fight", 1);

	set("coor/x", 390);
	set("coor/y", 780);
	set("coor/z", 190);
  set("door_name","殿门");
	set("door_dir","south");
	set("force_name","迟百城");
  set("outroom",__DIR__"dongling");
	setup();
}
