// Room: /d/guiyun/xiuxishi-f.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
        set("short", "女厢房");
        set("long", @LONG
这里是归云庄女弟子的休息室，摆着几张木床。床旁都有一支高脚
架子，用来挂衣物。屋角一张几凳，放了一盆兰花，散着淡淡幽香。
LONG );
	set("exits",([
		"west" : __DIR__"lianwuchang",
	]) );
	set("no_clean_up",0);
	set("no_fight", 1);
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
