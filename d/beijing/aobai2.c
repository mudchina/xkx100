// /d/beijing/aobai2.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "鳌府大门");
	set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了
大门两侧。门额上悬挂一方横匾，写着‘满洲第一勇士鳌拜府’几个大
字，门外有官兵把守，戒备森严。门上挂着两个灯笼，赫然写着“鳌”
字。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"east" : __DIR__"aobai1",
		"west" : __DIR__"aobai3",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -200);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	object *inv;
	if(dir=="west")
	{
		if( this_player()->query("meili")>50 )
		{
			inv = all_inventory(me);
			for(i=sizeof(inv)-1; i>=0; i--)
			if(inv[i]->query("weapon_prop") &&
				(inv[i]->query("equipped")))
				if(objectp(present("bing", environment(me))) &&
					living(present("bing",environment(me))))
					return notify_fail("官兵上前挡住你，朗声说道：这位"+ RANK_D->query_respect(me) + "请放下兵刃。\n你可以进府，但不得手持兵刃。\n");
			return ::valid_leave(me, dir);
		}
		else
		{
			if(objectp(present("guan bing", environment(me))) &&
				living(present("bing", environment(me))))
				return notify_fail("官兵拦住你骂道：“你以为你是谁啊？一个寻常百姓，难道还想进府见鳌大人？！\n你这" + RANK_D->query_rude(me) +"快给我滚远点儿，不然别怪我不客气！”\n");
		}
	}	
	return ::valid_leave(me, dir);
}
