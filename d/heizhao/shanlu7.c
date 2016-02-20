// Room: /heizhao/shanlu7.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你迈开大步径行入山。循着陡路上岭，约莫走了一个时辰，道
路更窄，有些地方需侧着身子方能过去。但见路旁山峰插天，想来
夏日里定能将骄阳全然遮去，倒也显见颇为清凉。
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"shanlu6",
		"northup"  : __DIR__"shanlu8",
	]));
	set("coor/x", -5010);
	set("coor/y", -1300);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}