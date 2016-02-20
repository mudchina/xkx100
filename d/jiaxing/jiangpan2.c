// Room: /d/jiaxing/jiangpan2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "江畔");
	set("long", @LONG
一条大江横亘在面前，江水浩浩，日日夜夜无穷无休地奔向大海。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"northwest": __DIR__"jiangpan1",
		"east"     : __DIR__"jiangpan3",
	]) );

	set("coor/x", 1590);
	set("coor/y", -1090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}