// /d/huashan/xiaofang.c 小木屋
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "小木屋");
	set("long", @LONG
一所摆设简单的小木屋。室内有一个香炉，墙上挂着一炳长剑。当
中坐着一位老者，穿著虽然朴素，却令人不由得心生敬仰。
LONG
	);
	set("exits", ([
		"out" : __DIR__"luoyan",
	]));
	set("objects", ([
		CLASS_D("huashan") + "/feng" : 1,
	]));
	set("coor/x", -860);
	set("coor/y", 120);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}
