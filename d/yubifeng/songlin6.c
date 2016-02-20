// /yubifeng/songlin6.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "大松林");
	set("long", @long
这座松林好长，走了半个时辰方始过完，一出松林，即到一座山峰脚下。山
峰虽非奇高，但宛如一根笔管般竖立在群山之中，陡削异常，莫说是人，即
令猿猴也是不易上去。	
long );
	set("exits", ([
		"east" : __DIR__"fengdi",
		"west" : __DIR__"songlin5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6100);
	set("coor/y", 5170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
