// Room: /d/huijiang/buluo2.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "回部部落");
	set("long", @LONG
此处三面是树林，北面的斜坡通向大草原，成群的牛羊在草原上吃
草嘻戏。远处天山山脉如同天地之间的一块屏障，把后面的一切都遮挡
住了。四外是几个帐篷。
LONG
	);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 4 */
		"west"      : __DIR__"zhangpeng3",
		"east"      : __DIR__"zhangpeng2",
		"south"     : __DIR__"buluo1",
		"northdown" : __DIR__"xiepo",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50050);
	set("coor/y", 9060);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
