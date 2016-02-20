// Room: /d/yueyang/taijiting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "太极亭");
	set("long", @LONG
太极亭为重檐锥顶小亭，亭内地面绘有阴阳合抱的太极图。在这里
可以饱览洞庭湖山景色。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"dongtingmiao1",
	]));
	set("coor/x", -1670);
	set("coor/y", 2350);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
