// Room: /city/yamen.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "衙门大门");
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的
牌子分放两头石狮子的旁边。门前侧面架子摆着个皮鼓，挂着一对木棰。
显然是供小民鸣冤用的。几名衙役在门前巡逻。
LONG );
	set("exits", ([
		"south" : __DIR__"tongsijie",
		"north" : __DIR__"yamenyuan",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 2,
//		__DIR__"npc/xunbu" : 1,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", -20);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if(!wizardp(me) && !me->query("officerlvl") && objectp(present("ya yi",environment(me)))&&dir=="north")
		return notify_fail("衙役喝道：“威……武……。”\n");
	return ::valid_leave(me, dir);
}