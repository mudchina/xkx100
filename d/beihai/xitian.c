// /d/beihai/xitian.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "西天梵境");
	set("long", @LONG
清朝时建的宗教建筑，主要是喇嘛教庙的样式。附近还有小西天、
阐福寺、大西天、极乐世界等。由这里向南就是去琼华岛的渡口。
LONG
	);
	set("exits", ([
		"west"      : __DIR__"jiulongbi",
		"southwest" : __DIR__"dukou1",
		"northeast" : __DIR__"jingqing",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
