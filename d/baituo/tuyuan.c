// Room: /d/baituo/tuyuan.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","兔苑");
	set("long", @LONG
这是个好玩的兔苑，几只大白兔静静地蹲在绿草地上吃草。西南方
是竹园。西面传来阵阵猛兽的嚎叫，东面有一个蛇园。
LONG );
	set("exits",([
		"east"  : __DIR__"sheyuan",
		"west"  : __DIR__"shoushe",
		"southwest" : __DIR__"zhuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/baitu" : 2,
	]));
	set("coor/x", -50000);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	me = this_player();
	myfam = (mapping)me->query("family");
	if((!myfam || (myfam["family_name"] != "白驼山派")) && (dir == "west"))
		return notify_fail("你不是白驼山弟子，不能进兽舍。\n");
	if((!myfam || (myfam["family_name"] != "白驼山派")) && (dir == "east"))
		return notify_fail("你不是白驼山弟子，不能进蛇园。\n");
	else return 1;
}
