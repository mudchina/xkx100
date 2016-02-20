// Room: /d/songshan/liangong.c 练功房
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是嵩山派练功房，地下凌乱地放着几个蒲团，几位嵩山弟子正
盘膝坐在上面打坐。
LONG );
	set("exits", ([
		"east" : __DIR__"westpath2",
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -50);
	set("coor/y", 910);
	set("coor/z", 90);
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
