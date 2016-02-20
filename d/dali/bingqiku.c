//Room: /d/dali/bingqiku.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","兵器房");
	set("long",@LONG
这里是镇南王府的兵器房，四周放这几个兵器架，上面是王府家
人弟子平时练剑用的竹剑。
LONG);
	set("objects", ([
            "/clone/weapon/zhujian" : 4,
            "/clone/weapon/changbian" : 1
	]));
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"chahua1",
	]));
        set("no_fight", 1);
	set("coor/x", -38970);
	set("coor/y", -69990);
	set("coor/z", 0);
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