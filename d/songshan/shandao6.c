// Room: /d/songshan/shandao6.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "峻极山道");
	set("long", @LONG
你走在嵩山峻极山道上，青松翠柏，山风岚雾，时来飘荡。远望山
下犬吠鸡啼，顿起仙凡之感。上面就是嵩山峻极禅院。
LONG );
	set("exits", ([
		"northup"   : __DIR__"junjigate",
		"southdown" : __DIR__"chaotian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	set("coor/x", -20);
	set("coor/y", 840);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
