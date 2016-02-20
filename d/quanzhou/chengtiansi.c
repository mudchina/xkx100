// Room: /d/quanzhou/chengtiansi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "承天寺");
	set("long", @LONG
这是泉州市民祭天求安的寺庙，以保佑年年得以五谷丰登，风调雨顺。寺
内广场中央有一法坛。承天寺西方通往刺桐南路。
LONG );
	set("exits", ([
		"west"      : __DIR__"southroad2",
		"northeast" : __DIR__"guitangxiang",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
