// Room: /d/heimuya/linjxd1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","林间小道");
	set("long", @LONG
你走在一条阴暗的林间小道上，两旁是阴森森的树林。一阵阵风吹
过树梢，发出沙沙的响声，令你不寒而栗。不过西边好象是一个山谷。 
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"south" : __DIR__"linjxd2",
		"north" : __DIR__"linjxd5",     
		"east"  : __DIR__"road1",
		"west"  : __DIR__"guang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}