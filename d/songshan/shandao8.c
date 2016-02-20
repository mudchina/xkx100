// Room: /d/songshan/shandao8.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "极顶山道");
	set("long", @LONG
你走在嵩山极顶山道，青松翠柏，山风岚雾，时来飘荡。远望山下
犬吠鸡啼，顿起仙凡之感。西上就是封禅台了。
LONG );
	set("exits", ([
		"eastdown" : __DIR__"shandao7",
		"westup"   : __DIR__"fengchantai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	set("coor/x", -26);
	set("coor/y", 850);
	set("coor/z", 86);
	setup();
	replace_program(ROOM);
}
