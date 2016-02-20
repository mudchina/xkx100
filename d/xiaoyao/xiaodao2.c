// xiaodao2.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条长长的林间小道，从东边一直通到西边，一眼望去，看不
到路的尽头。两旁百花争艳。令人留连忘返。南边好象有香味散发出来，
北边是个兵器房。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"shantang",
		"east" : __DIR__"xiaodao1",
		"west" : __DIR__"xiuxis",
		"north" : __DIR__"bingqif",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xiaoyao");
	set("coor/x", 60);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}