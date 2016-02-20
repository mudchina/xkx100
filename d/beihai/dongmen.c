// /d/beihai/dongmen.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "东门");
	set("long", @LONG
这里是北海的东门，木制的门框被漆成了大红色。虽然经过长期的雨打风吹，
颜色却仍旧十分鲜艳。看的出是有人专门维护的。门上没有显著的标志，但门口
站着几个卫士在聊天。
LONG
	);
	set("exits", ([
		"south"     : __DIR__"shulin",
		"northeast" : __DIR__"huafang",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -170);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
