// Room: /d/gaochang/shijie2.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
眼前遽然出现一大片松林。松林长得极密，石阶上铺满了厚厚的朽
黄的松针。踩在脚下，发出察察的响声。一只小松鼠吱地在眼前闪过，
消失在林海里。
LONG
	);

	set("outdoors", "gaochang");
	set("exits", ([
		"southdown" : __DIR__"shijie1",
		"northup" : __DIR__"shijie3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36500);
	set("coor/y", 10010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}