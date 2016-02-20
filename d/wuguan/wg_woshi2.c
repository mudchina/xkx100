// wg_woshi2.c

inherit ROOM;

void create()
{
	set("short","休息室");
	set("long", @LONG
这里是武馆内的休息室，屋子有点点旧，但是打扫的非常干净，一
排床铺靠墙摆着，你悄悄的走过去，找个空铺睡了下来。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_woshi1",
	]));
	set("no_clean_up", 0);
	set("no_fight",1);
	set("no_get",1);
	set("no_steal",1);
	set("no_get_from",1);
	set("sleep_room", 1);
	set("coor/x", 61);
	set("coor/y", -70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
