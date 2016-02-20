// Room: /d/heimuya/linjxd5.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","林间小道");
	set("long", @LONG
你走在一条阴暗的林间小道上，两旁是阴森森的树林。一阵阵风吹
过树梢，发出沙沙的响声，令你不寒而栗。忽然你发现树丛中有两点绿
芒，一闪即没！！
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"southup" : __DIR__"dating1",
		"north" : __DIR__"linjxd4",     
		"east"  : __DIR__"linjxd3",
		"west"  : __DIR__"linjxd5",
	]));
	set("objects",([
		__DIR__"npc/wolf" : 4 ,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}