// Room: /d/huijiang/caoyuan3.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
柔嫩的青草就踩在脚下，天上浮云飘过，牧羊的姑娘轻哼着小曲，
挥动皮鞭驱赶着牛羊，远处天山山脉高不可攀，一边的湖水在静静的波
动。几头苍鹰张着翅膀在空中缓缓滑过。
LONG
	);
	set("outdoors", "huijiang");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/ox" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"caoyuan",
	]));
	set("coor/x", -50040);
	set("coor/y", 9080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
