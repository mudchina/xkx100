// Room: /d/quanzhou/chenghuangxiang1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "城隍巷");
	set("long", @LONG
一条弯曲狭窄的碎石小路，两旁树木参差，阴暗森冷。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"northroad2",
		"northwest" : __DIR__"chenghuangmiao",
	]));
	set("coor/x", 1850);
	set("coor/y", -6460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
