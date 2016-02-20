// Room: /d/kunlun/hmszroad2.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条昆仑山上到处可见的山路。只是这里已到处可见梅树，梅
花盛开时到处一片火红，花香飘溢。西边是红梅山庄。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"westup"   : __DIR__"hmszhuang",
		"eastdown" : __DIR__"hmszroad1",
	]));
	set("outdoors", "hongmei");
	set("no_clean_up", 0);
	set("coor/x", -90020);
	set("coor/y", 10010);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
