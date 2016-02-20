// Room: /d/guiyun/xiuxishi-m.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
        set("short", "男厢房");
        set("long", @LONG
这里是归云庄男弟子的休息室，摆着几张木床。床旁都有一支高脚
架子，用来挂衣物。西首一扇小窗。外面是练武场。
LONG );
	set("exits",([
		"east" : __DIR__"lianwuchang",
	]) );
	set("no_clean_up",0);
	set("no_fight", 1);
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
