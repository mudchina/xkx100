// Last Modified by Sir on May. 22 2001
// xiuxishi.c 休息室

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是恒山白云庵的休息室。光线非常昏暗。房里没有什么别的东
西，只有中间放着一张收拾得舒舒服服的大床，有几个夜晚守庵的小师
太正在睡觉。
LONG
	);
	set("exits", ([
		"east" : __DIR__"byawest",		
	]));
	set("no_clean_up", 0);
	set("sleep_room",1);
	set("no_beg",1);
	set("no_fight",1);
	set("no_steal",1);

	set("coor/x", 20);
	set("coor/y", 3210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

