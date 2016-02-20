// Room: /d/xingxiu/xxh.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "星宿海");
	set("long", @LONG
这里是天山脚下的星宿海海边。因方圆几百里都是一望无际的湖泊
和沼泽，地形十分险恶。当地牧羊人称之为“海”。一旦有几只离群的
羊走迷在“海”里，便再也找不着了。臭名昭著的星宿派总坛便设在海
中央。
    南面有一条捷径可通往白驼山。
LONG );
	set("exits", ([
		"north"   : __DIR__"xxh1",
		"westup"  : __DIR__"tianroad3",
		"southup" : __DIR__"tianroad2",
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/zhaixing" : 1,
		__DIR__"npc/gushou"  : 1,
		__DIR__"npc/haoshou" : 1,
		__DIR__"npc/boshou" : 1,
	]) );
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -50000);
	set("coor/y", 20100);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "north" && dir != "westup")
	{
		return ::valid_leave(me, dir);
	}
	else
	{
		if (objectp(present("zhaixing zi", environment(me))) && 
			living(present("zhaixing zi", environment(me))))
		{
			if ((me->query("shen") > 100))
				return notify_fail("摘星子喝道：这位"+RANK_D->query_respect(me)+"休走！\n");
		}
		return ::valid_leave(me, dir);
	}
}
