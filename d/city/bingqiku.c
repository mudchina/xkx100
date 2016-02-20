// Room: /d/taohua/bingqi.c
// Last Modified by winder on Nov. 17 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long", @LONG
这里是兵器库，到处银光闪闪，让人眼花缭乱。宝刀、宝剑、金箍
棒，大刀、长剑、哨棒，短刀、短剑、短棍，各色各样的兵器应有尽有，
你一时不知道挑什么好。
LONG );
	set("exits", ([
		"north" : __DIR__"bingyin",
	]));
	set("objects", ([
		__DIR__"obj/gangdao": 1,
		__DIR__"obj/gangjian" : 3,
	]) );
//	set("no_clean_up", 0);
        
        create_door("north", "铁门", "south", DOOR_CLOSED);
	set("coor/x", 20);
	set("coor/y", -62);
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
		if (inv[i]->query("id") == "sword") j++;
	}
	if (j > 1)
                return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，带走一把钢剑就够啦。\n");
        return ::valid_leave(me, dir);
}