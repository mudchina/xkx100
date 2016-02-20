// Room: /d/wuyi/tianyoupath.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "天游石径");
	set("long", @LONG
你正攀爬在天游石径上。整个天游峰就是一块浑然的大石头。所以
有“一块石头玩半天”的说法。天游石径就凿在陡峭的石面上，上看青
天，下临无地，眼前就是光溜溜的石面。抬头就是前一个人的脚跟，万
丈深渊下是如蚁蠕动的人群排成一线。
人。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"westup"   : __DIR__"tianyoufeng",
		"eastdown" : __DIR__"chadong",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -4970);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

