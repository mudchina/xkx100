// Room: /beijing/kang1.c

inherit ROOM;

void create()
{
	set("short", "康府大门");
	set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子
镇住了大门两侧。门外有带刀侍卫把守，戒备森严。门上挂着两
个灯笼，赫然写着大大的“康”字。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"south" : __DIR__"wangfu3",
		"north" : __DIR__"kang2",
	]));
	set("objects", ([
		"/d/huanggong/npc/shiwei" : 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
    if(dir=="north")
    {
     if( this_player()->query("meili")>50 )
     {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop")&& (inv[i]->query("equipped")))
		if(objectp(present("shi", environment(me)))&&living(present("shi", environment(me))))
                    return notify_fail("侍卫上前挡住你，朗声说道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。\n"
                        "你可以进府，但不得手持兵刃。\n");
        return ::valid_leave(me, dir);
     }
     else
     {
         if(objectp(present("shi", environment(me)))&&living(present("shi", environment(me))))
            return notify_fail("侍卫拦住你骂道：“你以为你是谁啊？一个寻常百姓，难道还想进府见康大人？！\n你这" + RANK_D->query_rude(me) +"快给我滚远点儿，不然别怪我不客气！”\n");
     }
    }	
    return ::valid_leave(me, dir);
}
