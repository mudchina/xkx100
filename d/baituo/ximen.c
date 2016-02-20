// Room: /d/baituo/ximen.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","西门");
	set("long", @LONG
这是个白驼山庄的西门。拱月形的竹门分外雅致，门上挂着一块竹
牌 (pai)。西门外面杂草丛生。
LONG	);
	set("exits",([
		"west" : __DIR__"cao1",
		"east" : __DIR__"changlang",
	]));
	set("item_desc",([
		"pai" : "西门外面有毒蛇出没，慎行。\n" ,
	]));
	set("objects",([
		__DIR__"npc/menwei" : 1,
	]));
	set("outdoors", "baituo");
	set("coor/x", -50030);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	if( (dir == "east") && ((int)me->query("shen")>300) &&
		objectp(present("men wei", environment(me))) )
		return notify_fail("门卫把手一拦：你不能进去！\n");
	if( (dir == "west") &&((int)me->query("combat_exp") < 300) &&
		objectp(present("men wei", environment(me))) )
		return notify_fail("门卫把手一拦：你的经验太低，会被毒蛇咬死的！还是不要乱闯的好。\n");
	return ::valid_leave(me, dir);
}

