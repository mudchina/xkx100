// Room: /d/quanzhou/hongfulou.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鸿福楼");
	set("long", @LONG
这是泉州城中字号最老的客栈蒹酒楼，生意非常兴隆。许多江湖人
物在这里高谈阔论，所以这里是个打听到情报的好地方。墙上挂着一个
牌子(paizi)。北面是一间马厩。
LONG );
	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五十两白银。\n",
	]));
	set("exits", ([
		"west"   : __DIR__"northroad1",
		"north"  : __DIR__"majiu",
		"up"     : __DIR__"kedian2",
	]));
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6520);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian16_b"->foo();
}
int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！\n旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}

