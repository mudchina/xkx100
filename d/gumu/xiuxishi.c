// xiuxishi.c 休息室
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这是间很大的房间，光线非常昏暗。房里没有什么别的东西，只有
中间一张小桌，里墙放着一张收拾得舒舒服服的大床，床上的被褥也整
理得整整洁洁的，看着就让人想睡觉。
LONG	);
	set("exits", ([
		"east" : __DIR__"mudao02",
	]));
	set("sleep_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_clean_up", 0);
	set("coor/x", -3240);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
