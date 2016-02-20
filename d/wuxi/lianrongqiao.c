// Room: /d/wuxi/lianrongqiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "莲蓉桥");
	set("long", @LONG
莲蓉桥俗称北门大桥，因为是一条官道，桥面修得很宽很平坦，上
面足可让六匹马并行而过。这里由于官兵盘问较紧，不准小商小贩来此
营生，经过的人也不太多。桥面显得十分干净，也很冷清，向南去是城
里，向北是长江边。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"road5",
		"south" : __DIR__"northgate",
	]));
	set("no_clean_up", 0);
	set("coor/x", 370);
	set("coor/y", -750);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}