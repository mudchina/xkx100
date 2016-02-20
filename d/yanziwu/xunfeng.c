// Room: /d/yanziwu/xunfeng.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "熏风轩");
	set("long", @LONG
一个精美的小轩，建在水边，一半横卧万顷太湖波涛中。湖面风势
徐来，带动轩角风铃一阵阵低吟。远望万千波涛，如少女的碧绿长裙轻
舞，渐行渐近，终于消失在轩下，真是无边景致，全在心情。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"southwest"   : __DIR__"path13",
	]));
	set("coor/x", 1270);
	set("coor/y", -1210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}