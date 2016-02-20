// Room: /d/heimuya/didao5.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","秘道");
	set("long", @LONG
走在里面，你不觉想到这似乎在每个角落都藏着无限杀机，你感到
近了近了，越来越近了。
LONG );
	set("exits",([
		"east" : __DIR__"didao3",
		"west" : __DIR__"didao3",
		"north" : __DIR__"didao2",
		"south" : __DIR__"didao1",
	]));
	set("objects",([
		__DIR__"npc/snake" : 4,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}