// Room: /d/heimuya/baistep2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","长廊");
	set("long", @LONG
这里是白虎堂的长廊。两边一片狼藉，看样子刚被洗劫一场，遍地
横尸，惨不忍赌。
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"north" : __DIR__"baistep1",
		"south" : __DIR__"baihutang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
