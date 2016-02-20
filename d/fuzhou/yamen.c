// Room: /d/fuzhou/yamen.c
// Date: may 12. 1998 Java

inherit ROOM;

void create()
{
	set("short", "提督衙门");
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的
牌子分放两头石狮子的旁边。前面有一个大鼓，几名戈什哈站在门前。
LONG );
	set("exits", ([
		"east" : __DIR__"nandajie",
	]));
	set("objects", ([
		__DIR__"npc/geshiha" : 2,
	]));
	set("no_fight", "1");
	set("no_beg", "1");
	set("coor/x", 1830);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("geshiha", environment(me))) && dir != "east")
		return notify_fail("戈什哈喝道：“施大人已去校场阅兵，你来何干？”\n");
	return ::valid_leave(me, dir);
}
