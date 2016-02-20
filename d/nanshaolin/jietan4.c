// Room: /d/nanshaolin/jietan4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "戒坛");
	set("long", @LONG
这是一个正方形，四角攒尖顶的亭台式建筑。是寺中僧徒受戒的地
方。坛上正中放有佛身相连，向背而坐的双面铜铸佛像，面北的是药师
佛，面南的为阿弥陀佛。坛上空无一人，寂静无声，越发显得此处的庄
严肃穆。
LONG );
	set("exits", ([
		"west"      : __DIR__"jietan3",
		"south"     : __DIR__"jietan2",
		"northwest" : __DIR__"fatang",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6120);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

