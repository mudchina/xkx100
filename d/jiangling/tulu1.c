//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "黄土路");
	set("long", @LONG
这是一条黄土路，不时可见江湖中人背着包袱，别着刀剑往北走去。
地上有许多马车碾过的痕迹。
LONG );
	set("exits", ([
		"south"     : __DIR__"tulu2",
		"north"     : __DIR__"hzjie5",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2150);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}