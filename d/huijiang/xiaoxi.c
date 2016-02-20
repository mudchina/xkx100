// Room: /d/huijiang/xiaoxi.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set ("short", "小溪流");
	set ("long", @LONG
在差刺交错的岩石之间流淌的一条小溪流。清澈的河底是光滑的鹅
卵石。流淌的溪水微微带着香气，溪水中无数小块碎冰互相撞击，发出
清脆声音，叮叮咚咚，宛如仙乐。
LONG);
	set("exits", ([ /* sizeof() == 2 */
		"northup" : __DIR__"xiaoxi1",
		"east"    : __DIR__"gebi2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huijiang");
	set("coor/x", -50020);
	set("coor/y", 9000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
