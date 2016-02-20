// bingqifang.c 兵器房
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "兵器房");
	set("long", @LONG
这里是华山派的兵器房，四周放这几个兵器架，上面是华山派各弟
子平时练剑用的竹剑。
LONG );
	set("exits", ([
		"west" : __DIR__"square",
	]));
	set("objects", ([ 
		WEAPON_DIR"sword/zhujian" : 4
	]));
	set("no_fight", 1);

	set("coor/x", -850);
	set("coor/y", 200);
	set("coor/z", 120);
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
	if (j > 1) return notify_fail("这位" + RANK_D->query_respect(me) + "别那么贪心，带走一把竹剑就够啦。\n");
	return ::valid_leave(me, dir);
}
