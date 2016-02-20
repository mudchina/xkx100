//      kufang.c 库房

inherit ROOM;
void create()
{
	set("short","库房");
	set("long",@LONG
这里是练武场旁边的小库房，房里密不通风，只有一丝光线从屋檐
小缝中投射进来。房中有些备用的武器，都是雪山弟子日常练功需要用
到的兵器。
LONG );
	set("exits",([
		"east" : __DIR__"chang",
	]));
	set("objects", ([
		"/clone/weapon/zhujian" : random(4),
		"/clone/weapon/gangdao" : random(4),
		__DIR__"obj/mugun" : random(4),
		__DIR__"obj/falun" : random(4),
		WEAPON_DIR"treasure/yinlun" : random(2),
	]));
	set("coor/x", -70060);
	set("coor/y", -19900);
	set("coor/z", 120);
	setup();
}
int valid_leave(object me, string dir)
{
	int i, w, x, y, z;
	object *inv;
	inv = all_inventory(me);
	i = sizeof(inv);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (inv[i]->query("id") == "zhujian") w++;
		if (inv[i]->query("id") == "fa lun") x++;
		if (inv[i]->query("id") == "mu gun") y++;
		if (inv[i]->query("id") == "blade") y++;
	}
	if (w>1 || x>1 || y>1 || z>1)
                return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，每样带走一把就够啦。\n");
        return ::valid_leave(me, dir);
}
