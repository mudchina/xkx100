// Room: /qingcheng/yinxing.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "古银杏树");
	set("long", @LONG
观前古银杏树相传为张天师手植，高可十余丈，腰围七、八人
合抱，枝叶扶疏，苍盖如云。
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"east"     : __DIR__"tianshidong",
	]));
        set("objects", ([
                "/clone/medicine/vegetable/danggui" : random(2),
        ]));
	set("coor/x", -8110);
	set("coor/y", -910);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}