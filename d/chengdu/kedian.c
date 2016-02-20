// Room: /chengdu/kedian.c
// Date: Feb.14.1998 by Java

inherit ROOM;

void create()
{
	set("short", "锦城驿");
	set("long", @LONG
锦城驿是全西南最大的客店，生意非常兴隆。外地游客多选择这里
落脚，你可以在这里打听到各地的风土人情。店小二里里外外忙得团团
转，沉重的川味官话你是实在听不顺耳。这是成都督府官办的客栈，接
待着各地入川的官差浪人。墙上挂着一个牌子(paizi)。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五十两白银。\n",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("exits", ([
		"up"    : __DIR__"kedian2",
		"south" : __DIR__"dongjie1",
		"north" : __DIR__"majiu",
	]));
	set("coor/x", -8040);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian3_b"->foo();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
