// Room: /d/suzhou/yamengate.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "衙门大门");
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的
牌子分放两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。
几名衙役在门前巡逻。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"yamen",
	]));

	set("objects", ([
		__DIR__"npc/yayi" : 2,
	]));
	set("coor/x", 840);
	set("coor/y", -1005);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("ya yi", environment(me))) &&
		dir == "north")
		return notify_fail("衙役喝道：“威……武……。”\n");
	return ::valid_leave(me, dir);
}
