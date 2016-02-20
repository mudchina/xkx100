// /d/beihai/jingji.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "敬跻堂");
	set("long", @LONG
这里是承光殿北的敬跻堂，阔十五间，缘城墙成环抱之势。临窗眺
望，可以一览北海南面的风光。堂内整齐的放着几把檀木椅子。中间是
一张八仙桌。虽然不经常有人来坐，却仍然被打扫的一尘不染。
LONG
	);
	set("exits", ([
		"south" : __DIR__"chengguang",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

