// shulin1.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把
琼天大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然
发出的声响。
LONG );
	set("exits", ([
		"north" : __DIR__"shulin1",
		"south" : __DIR__"shulin1",
		"east" : __DIR__"shulin2",
		"west" : __DIR__"xiaodao4",
	]));
	set("outdoors", "xiaoyao");
	set("no_clean_up", 0);
	set("coor/x", 100);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}