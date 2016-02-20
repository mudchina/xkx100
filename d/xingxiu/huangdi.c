// Room: /d/xingxiu/huangdi.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;
void create()
{
	set("short", "山前荒地");
	set("long", @LONG
你站在石山前的荒地上。这儿人迹罕见，放眼望去，尽是枯树败草。
朔风萧杀，令人心惊胆颤。路边有几个星宿弟子在练功，同时监视着行
人一举一动。你没事，还是快回吧。
LONG);
	set("objects", ([
		CLASS_D("xingxiu")+"/feitian" : 1,
		__DIR__"npc/xxdizi" : 1,
	]));
	set("exits", ([
		"south"     : __DIR__"xxh2",
		"northup"   : __DIR__"riyuedong1",
	]));
	set("outdoors", "xingxiu");
	set("coor/x", -50000);
	set("coor/y", 20300);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if (dir =="northup" && present("feitian zi", environment(me)) &&
		(!myfam || myfam["family_name"] != "星宿派") &&
		me->query("combat_exp") < 100000) 
		return notify_fail("飞天子挡住了你：像你这样糟糕的邪派弟子怎么可以去拜见我们老仙？\n");
	return ::valid_leave(me, dir);
}

