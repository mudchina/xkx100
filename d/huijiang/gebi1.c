// Room: /d/huijiang/gebi1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "戈壁");
	set("long", @LONG
焦热的阳光晒着茫茫的戈壁，天地之间只剩下黄色的沙，连绵起伏
的沙丘一眼望不到边。前面不远的沙地上微微随风而动的是沙漠中的铁
草，耐旱，看来你快走出这片沙漠了。
LONG );
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : "/d/xingxiu/shanjiao",
		"west"      : __DIR__"shamo1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 9000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
