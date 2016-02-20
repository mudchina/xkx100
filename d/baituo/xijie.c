// Room: /d/baituo/xijie.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "西街");
	set("long", @LONG
这里是小镇的西街。北边有个酒店，门前树立着高高的旗杆，一块
青布幌子迎风飘扬，上面印着朱红色的大字‘酒’。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"west" : __DIR__"bridge",
		"east" : __DIR__"dongjie",
		"north" : __DIR__"jiudian",
	]));
	set("objects",([
		__DIR__"npc/man" : 1,
		__DIR__"npc/snaker"  :1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -49990);
	set("coor/y", 19980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
