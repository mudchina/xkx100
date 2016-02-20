// Room: /d/huashan/jzroad4.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short", "中条山森林");
	set("long", @LONG
你走在中条山路上。路径狭小，周围茂密森林里，传来阵阵野兽夜
禽的嘶鸣，听来让人毛骨悚然。
LONG );
	set("exits", ([
		"southup"  : __DIR__"jzroad5",
		"westdown" : __DIR__"jzroad3",
	]));
	set("outdoors", "zhongtiao");
	set("no_clean_up", 0);
	set("coor/x", -920);
	set("coor/y", 210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
