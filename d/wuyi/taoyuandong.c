// Room: /d/wuyi/taoyuandong.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "桃源洞");
	set("long", @LONG
“喜无樵子复观弈，怕有渔郎来问津”。曲径通幽，翠竹掩映，山
门洞开，豁然开朗。这里就是六曲北岸松鼠涧尽头的小桃源。巨石相倚
的小洞，仅容一人通过。辗转进入石门，门上镌刻“桃源洞”三字。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"enter"  : __DIR__"taohuayuan",
		"south"  : __DIR__"path7",
		"north"  : __DIR__"path8",
		"eastup" : __DIR__"tianyoupath2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -4970);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

