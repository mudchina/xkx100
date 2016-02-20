// Room: /d/chengdu/lingmu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "陵墓");
	set("long", @LONG
这里有一座很大的陵墓，你走到这里，感觉怪怪的，不知道有什么
地方不对，也许是这里的气氛使人有些压抑吧，有个扫墓人在那里不停
地唉声叹气。
LONG	);
	set("exits", ([
		"east" : __DIR__"wuhouci",
	]));
	set("objects",([
		 __DIR__"npc/saomuren" : 1,
	]));
	set("outdoors", "chengdu");
	set("coor/x", -8080);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

