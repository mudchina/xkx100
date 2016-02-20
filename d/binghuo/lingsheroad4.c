// Room: /binghuo/lingsheroad4.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在树林中的小路上，四周僻静得让你感到窒息般的异常。密
密层层的树林遮天蔽日，你甚至听不到一点虫鸣。山顶有座小屋岛。
LONG );
	set("outdoors", "lingshe");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown"  : __DIR__"lingshegang",
		"westup"    : __DIR__"lingshetop",
	]));
	setup();
	replace_program(ROOM);
}

