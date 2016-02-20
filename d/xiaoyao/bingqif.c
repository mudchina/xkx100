// bingqif.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "打铁屋");
	set("long", @LONG
这里是树林深处的一间小石屋，看来是打造兵器的，屋子中有个大
火炉好烫的呢，屋中还有一张石几，上面摆放着一些早就已经打造好的
兵器。
LONG );
	set("exits", ([
		"south" : __DIR__"xiaodao2",
	]));
	set("no_clean_up", 0);
	set("objects", ([
	       __DIR__"obj/blade": 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 60);
	set("coor/y", -490);
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
		if (inv[i]->query("id") == "blade") j++;
	}
	if (j > 1)
                return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，带走一口钢刀就够啦。\n");
        return ::valid_leave(me, dir);
}