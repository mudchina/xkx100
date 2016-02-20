// Room: /d/heimuya/grass1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM; 
void create()
{
	set("short", "草地");
	set("long",@LONG
你走在一片草地。草地东边有一片墓地。
LONG );
	set("exits", ([
		"east"    : __DIR__"mudi",
		"south"   : __DIR__"fen0", 
		"north"   : __DIR__"grass2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "heimuya");    
	set("coor/x", -3030);
	set("coor/y", 4010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}