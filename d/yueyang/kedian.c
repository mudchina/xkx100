// Room: /d/yueyang/jiudian.c 
// Last Modifyed by Winder on Dec. 4 2001
inherit ROOM;

void create()
{
	set("short", "牡丹楼");
	set("long", @LONG
吕洞宾三醉洞庭的故事无人不知，而白牡丹戏洞宾的传说在这里也
是人人皆晓。这里就是当年白牡丹戏洞宾的所在。楼上是行商休息的地
方，楼下靠边上，有一个柜台，柜台后有一个帐房先生正在拨着算盘珠
子，一边还拿枝笔记着什么。一个店小二看到你的到来，笑吟吟的迎上
前来。边上的楼梯前挂着个告示(paizi)。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五十两白银。\n"
	]));
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("exits", ([
		"up"   : __DIR__"kedian2",
		"west" : __DIR__"nanjie",
	]));

	set("coor/x", -1400);
	set("coor/y", -2280);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian18_b"->foo();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎么着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎么不住店就走了呢！\n旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
