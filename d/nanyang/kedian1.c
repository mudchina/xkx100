// Room: /d/nanyang/kedian.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("short", "悦来客栈");
	set("long", @LONG
这是一家远近闻名的悦来客栈，生意非常兴隆。外地游客多选择在
这里落脚，你可以在这里打听到各地的风土人情。店小二里里外外忙得
团团转，接待着南腔北调的客人。墙上挂着一个牌子(paizi)。
LONG );
	set("valid_startroom", 1);
	set("no_fight", 1);
	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五两白银。\n",
	]));
	set("objects", ([
		__DIR__"npc/xiao-er" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nanyang",
		"up" : __DIR__"kedian2",
	]));
//	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 500);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
