// /guanwai/road7.c
inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
你走在一条碎石铺成的大道上，道两旁种着笔直通天的白杨树，放
眼向两侧望去，全是无边无际的田野，遥见天边处仿佛有几座低矮的丘
陵，为平坦的大地增加了几许柔和的曲线。呼啸而过的狂风冻得人直打
哆嗦。
LONG );
	set("exits", ([
		"north" : __DIR__"road8",
		"south" : __DIR__"road6",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	set("coor/x", 6040);
	set("coor/y", 5170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}