// Room: /d/huijiang/buluo.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "回部部落");
	set("long", @LONG
此处三面是树林，一面的斜坡下，是一望无边的草原，远处高山在
云雾中闪现，各种鸟儿在枝头鸣叫。斜坡的这边是老大一片空地，几个
帐篷就扎在空地的中央。
LONG
	);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"shulin",
		"west"  : __DIR__"shulin1",
		"south" : __DIR__"shulin2",
		"north" : __DIR__"buluo1",
	]));

	set("no_clean_up", 0);
	set("coor/x", -50050);
	set("coor/y", 9040);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
