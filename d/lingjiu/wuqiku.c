//ROOM: wuqiku.c

inherit ROOM;

void create()
{
	set("short", "蓼风轩");
	set("long",@LONG
这是『灵鹫宫』弟子的兵器库，你环顾四周，发现墙上嵌满了各式
兵器，仔细一看，原来满墙满壁竟随依各般兵器之形抠出槽子，兵刃就
悬于槽内。你不由暗赞：“好精致的想头！”
LONG );
	set("exits", ([
		"east" : __DIR__"changl5",
	]));
	set("objects",([
		"/d/village/obj/zhujian" : 4,
	]));
	set("coor/x", -51030);
	set("coor/y", 30150);
	set("coor/z", 70);
	setup();
}
int valid_leave(object me, string dir)
{
	int i, j;
	object *inv;
	inv = all_inventory(me);
	i = sizeof(inv);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (inv[i]->query("id") == "zhujian") j++;
	}
	if (j > 1)
		return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，带走一把竹剑就够啦。\n");
		return ::valid_leave(me, dir);
}