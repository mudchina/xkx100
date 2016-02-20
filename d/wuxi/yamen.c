// Room: /d/wuxi/yamen.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "衙门大门");
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的
牌子分放两头石狮子的旁边。前面有一个红漆大鼓，显然是供小民鸣冤
用的。几名衙役站在门前，不怒自威。
LONG );
	set("exits", ([
		"south" : __DIR__"eastroad1",
		"north" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		"/d/city/npc/yayi" : 4,
	]));
	set("coor/x", 380);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if(!wizardp(me) && !me->query("officerlvl") && objectp(present("ya yi",environment(me)))&&dir=="north")
		return notify_fail("衙役喝道：“威……武……。”\n");
	return ::valid_leave(me, dir);
}
