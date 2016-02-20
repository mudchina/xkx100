// Room: /city/shixingting.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "诗兴亭");
	set("long", @LONG
亭立之处，是全园的最高点。亭子围以白石栏槛，可以供四人坐。
近观山势起伏，怪石嶙峋，又有松柏穿插其间，玉兰花树，荫盖于前。
远眺则宅第鳞次，俯视则水平如镜，仰视则云行天际。真真是诗兴亭。
LONG );
	set("exits", ([
		"northdown"  : __DIR__"luqiao",
		"southdown"  : __DIR__"tianjing",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 2);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}