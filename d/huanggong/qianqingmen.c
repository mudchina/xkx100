// Room: /d/huanggong/qianqingmen.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "乾清门");
	set("long", @LONG
这是皇宫后廷的正门. 门中有一个宝座, 有些时候, 皇上为表示亲
政, 就在这听取各衙门主管依次奏事, 这叫御门听政.
LONG
	);
	set("outdoors", "huanggong");
        set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"rijing",
		"west"      : __DIR__"yuehua",
		"south"     : __DIR__"baohedian",
		"north"     : __DIR__"qianqinggong",
		"northeast" : __DIR__"jiuqingfang",
		"northwest" : __DIR__"junjichu",
		"southeast" : __DIR__"jingyunmen",
		"southwest" : __DIR__"longzongmen",
	]));
	set("objects", ([
		__DIR__"npc/duolong" : 1,
	]));
	set("coor/x", -200);
	set("coor/y", 5280);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if ((dir=="north") &&
	objectp(present("duo long", environment(me))))
		return notify_fail("多隆拦住你说：此处禁地，请止步。\n");

	return ::valid_leave(me, dir);
}