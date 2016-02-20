//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条黄泥山道，不时可见江湖中人背着包袱，别着刀剑走来走
去。地上有许多车马碾过的痕迹。东边是一片乱葬冈子。
LONG );
	set("exits", ([
		"east"  : __DIR__"shangang1",
		"west"  : __DIR__"shandao4",
		"north" : __DIR__"dongmen",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}