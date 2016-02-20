// Room: /beijing/guancaidian.c

inherit ROOM;

void create()
{
	set("short", "棺材店");
	set("long", @LONG
这是一家棺材店，一进门，一股楠木味扑鼻而来。屋子里很阴暗，
桌子椅子都很破旧。往东是一间内室，一个三十出头的精壮汉子挡在门
口。
LONG );
	set("item_desc", ([
		"guancai" : "本店出售棺材，每个五十两黄金。\n",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/gaoyanchao" : 1,
	]));
	set("exits", ([
		"northwest" : __DIR__"alley2",
		"east"      : __DIR__"guancai2",
	]));
	set("coor/x", -219);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("money_paid") && dir == "up" )
	{
        if(objectp(present("gaoyanca", environment(me))))
        return notify_fail("高彦超一下挡在楼梯前，怒道：先交钱！\n");
        }
	if ( me->query_temp("money_paid") && dir == "west" )
	return notify_fail("高彦超跑到门边拦住：客官已经付了金子，怎麽不上楼就走了呢！\n");
	return ::valid_leave(me, dir);
}
