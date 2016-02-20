// Room: /d/wuyi/sanyangfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "三仰峰");
	set("long", @LONG
位于七曲溪北的三仰峰，三片巨石昂首向东，直插云霄。远看如三
面厚重的旌旗，迎风招展。峰上古树环匝、绿叶成荫，碧霄洞上勒有明
代万历林培所书“武夷最高处”五个大字。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"       : __DIR__"path9",
		"south"      : __DIR__"path8",
		"northeast"  : __DIR__"path10",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("coor/x", 1370);
	set("coor/y", -4950);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

