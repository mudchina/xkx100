// Room: /d/henshan/kefang.c
// Date: Sep.1 2001 by ahda

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是间整洁的客房，因门窗常闭着，光线很昏暗。房里别无他物，
只有两边放着几张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG );
	set("sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"liufudayuan",
	]));
	set("coor/x", -410);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

