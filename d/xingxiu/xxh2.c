// Room: /d/xingxiu/xxh2.c
// Last Modified by winder on Apr. 25 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "星宿海");
	set("long", @LONG
这里是星宿海。因方圆几百里都是一望无际的湖泊和沼泽，当地牧
羊人称之为“海”。也因阴暗潮湿，毒虫繁殖甚富。星宿弟子常来此捕
捉毒虫，以备练毒之用。这里通向星宿海的深处。
LONG);
	set("exits", ([
		"east" : __DIR__"xxh4",
		"south" : __FILE__,
		"west" : __DIR__"xxh1",
		"north" : __DIR__"xxh3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 20200);
	set("coor/z", 0);
	set("outdoors", "xingxiu");
	setup();
//	replace_program(ROOM);

}
#include "/d/xingxiu/xxh.h";
