// Room: /d/suzhou/zhipoxuan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "揖峰指柏轩");
	set("long", @LONG
这里曾是为园主接待宾客和亲友的地方，有时也作为演戏说书或写
诗作画之处。轩名取朱熹“前揖庐山，一峰独秀”和高启的“笑指庭前
柏”句诗意。轩内摆设古香古色。凭轩眺望，满目石峰嶙峋，古柏虬枝
盘绕，旧有桃源“十八景”之称。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest"  : __DIR__"shizilin",
	]));
	set("coor/x", 870);
	set("coor/y", -1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
