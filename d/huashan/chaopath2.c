// Room: chaopath2.c 朝阳峰小路
//Date: Oct. 2 1997 by Venus

inherit ROOM;

void create()
{
	set("short","朝阳峰小路");
	set("long",@LONG
这里是朝阳峰小路，山势陡峭，两边下临深谷，一不小心都会掉了
下去。西面有一条小路，长草没径。
LONG);
	set("outdoors", "huashan");
	set("exits",([ /* sizeof() == 1 */
		"eastup"   : __DIR__"chaoyang",
		"westup"   : __DIR__"ziqitai",
		"southwest": __DIR__"chaopath1",
	]));
	set("objects", ([
		__DIR__"npc/shi-daizi" : 1,
	]));
	set("coor/x", -860);
	set("coor/y", 220);
	set("coor/z", 120);
	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/chaoyang", 1);
	return;
}

int valid_leave(object me, string dir)
{
	if (dir=="eastup" &&
		objectp(present("shi daizi", environment(me))) &&
		(me->query("family/master_id")!="gao laozhe") &&
		(me->query("family/master_id")!="ai laozhe"))
		return notify_fail("施戴子喝道：上面是两位长老清修之处，这位" + RANK_D->query_respect(me) + "请止步！\n");
	return ::valid_leave(me, dir);
}
