// Room: /d/xingxiu/xxhb3.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "星宿海");
	set("long", @LONG
这里是星宿海的尽头。因为附近有野羊出没，所以星宿派弟子常常
在此烤羊肉串吃。当打不到野羊时，他们就抢山下牧人的羊。
LONG );
	set("exits", ([
		"southeast" : __DIR__"xxhb1",
		"southwest" : __DIR__"xxhb2",
	]));
	set("objects", ([
		__DIR__"npc/boshou"  : 1,
		__DIR__"npc/obj/yangrou" : 2
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -50000);
	set("coor/y", 20500);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
