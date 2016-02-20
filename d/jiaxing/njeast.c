// Room: /d/taohua/njeast.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "牛家村口");
	set("long", @LONG
这是一座小村落的东村口。村子很小，笼罩在一片寂静中。南边隐
约可以看到一条大江。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");
	set("exits", ([
		"west": __DIR__"njroad3",
	]) );
	set("objects", ([
		"/d/village/npc/kid" : 1,
	]) );

	set("coor/x", 1590);
	set("coor/y", -1050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}