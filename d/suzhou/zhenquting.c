// Room: /d/suzhou/zhenquting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "真趣亭");
	set("long", @LONG
真趣亭内高高悬挂御笔题写的“真趣”匾一块。亭内装饰精致金碧
辉煌。梁架、围屏、裙板上雕刻的人物、花鸟图案惟妙惟肖。在此可以
环览全园景色。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"wenmeige",
		"northwest" : __DIR__"yanyutang",
	]));
	set("coor/x", 880);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
