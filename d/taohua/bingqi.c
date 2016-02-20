// Room: /d/taohua/bingqi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long", @LONG
这是一间存放兵器的屋子。刀、枪、剑、戟等各种兵器都按类放在
各自的兵器架上。整个屋子落满灰尘，显然已经好久没人来过。
LONG );
	set("exits", ([
		"north" : __DIR__"zoulang3",
	]));
	set("objects", ([
		__DIR__"obj/taojian": 5,
		__DIR__"obj/shizi" : 1,
		__DIR__"obj/ziyuxiao" : 1,
		"/clone/weapon/changjian" : 2,
//		__DIR__"npc/machine-bonze" : 4,
	]) );
//	set("no_clean_up", 0);
	set("coor/x", 8990);
	set("coor/y", -3020);
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
		if (inv[i]->query("id") == "taomu jian") j++;
	}
	if (j > 1)
                return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，带走一把桃木剑就够啦。\n");
        return ::valid_leave(me, dir);
}