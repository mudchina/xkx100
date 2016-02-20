//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "西山小路");
	set("long", @LONG
西边都是荒山，乱石嶙峋，那是连油桐树、油茶树也不能种的。那
边荒山之中，有一个旁人从来不知的山洞。翻过两个山坡，来到一个大
山洞前。
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"maxipu",
		"enter"     : __DIR__"dashandong",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1620);
	set("coor/y", -2210);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}