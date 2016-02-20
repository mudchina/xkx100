// /kaifeng/caidi4.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "菜地");
	set("long", @LONG
这片菜园子几畦地里种了一些时鲜蔬菜。另外有几个木桩搭起的菜
架子，供一些爬藤的蔬菜生长，不过你举目看去，老大的一片菜园子，
居然疏疏落落的没有几棵菜。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"caidi2",
		"north" : __DIR__"caidi1",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
