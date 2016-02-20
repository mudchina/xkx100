// caodi2.c 草地
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这里是一片草地，草很深，几乎淹没了小腿。草间散布着一些奇花，
微风吹过，芬芳扑鼻。你听到时而有“嗡嗡嗡”的声音，看见有一些个
头奇大的白色的蜜蜂在草地上飞舞盘旋。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"west"      : __DIR__"caodi",
		"southeast" : __DIR__"hanshuitan",
	]));
	set("objects", ([
		__DIR__"npc/yufeng" : random(3),
	]));
	set("coor/x", -3210);
	set("coor/y", 40);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
