// Room: /d/jiaxing/njroad4.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "村中小路");
	set("long", @LONG
一条村中的小路。往南边看已经可以看到大江了，江水的咆哮声不
时地敲击着你的耳鼓。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"north": __DIR__"njroad3",
		"south": __DIR__"njroad5",
	]) );
	set("objects", ([
		"/d/village/npc/boy" : 1,
	]) );

	set("coor/x", 1580);
	set("coor/y", -1060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}