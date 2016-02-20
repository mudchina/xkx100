// Room: /d/xingxiu/xxhb1.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "星宿海");
	set("long", @LONG
这儿便是星宿海的尽头了。举目遥望, 周围是无际的湖泊和沼泽。
虽是荒芜, 然阴暗潮湿, 毒虫繁殖甚富。星宿弟子常来此捕捉毒虫,以
备练毒之用。
LONG );
	set("objects", ([
		__DIR__"npc/gushou"  : 1,
	]) );
	set("exits", ([
	     "southwest" : __DIR__"riyuedong1",
	     "northwest" : __DIR__"xxhb3",
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -49990);
	set("coor/y", 20400);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
