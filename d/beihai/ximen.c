// /d/beihai/ximen.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "西门");
	set("long", @LONG
这里是北海的西门，木制的门框被漆成了大红色。虽然经过长期的
雨打风吹，颜色却仍旧十分鲜艳。看的出是有人专门维护的。门上没有
显著的标志，但门口站着几个卫士在聊天。东面远远可以看见团城上飘
扬的旗帜。
LONG
	);
	set("exits", ([
		"east"       : __DIR__"yanxiang",
		"north"      : __DIR__"xiaolu1",
		"southwest"  : "/d/beijing/xichang1",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
