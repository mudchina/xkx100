// Room: /d/kunlun/lianwuchang.c
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @long
这里是练武场，昆仑派的很多弟子在这里练习武功，在练武场的一
角，有一个专门用来练武的梅花桩(zhuang)，许多弟子都围在这里练习
腿功。
long);
	set("exits",([
		"west" : __DIR__"huayuan1",
	]));
	set("item_desc", ([
		"zhuang" : "这是一片梅花桩，跳上去可以练习腿功，许多弟子在上面扎马(zhama)。\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40080);
	set("coor/z", 90);
	setup();
}
int init()
{
	add_action("do_zhama","zhama");
}

int do_zhama(string arg)
{
	object me;
	me = this_player();
	if ( !living(this_player()) || arg != "zhuang" )
		return notify_fail("你要在哪扎马？\n");
	if ((int)me->query_skill("leg", 1) > 100)
		return notify_fail("你的腿功已经很高了,这种练习对你没什么作用。\n");
	if ( (int)me->query("qi")<30)
	{
		me->receive_damage("qi", 10);
		write("你的腿已经酸了,还是先休息一会吧！\n");
		return 1;
	}
	me->receive_damage("qi", random(25));
	message_vision("$N正在梅花桩上扎着马步。\n", me);
	write("你全神贯注的在梅花桩上扎了一柱香时间的马步，感觉基本腿法又进了一步。\n");
	me->improve_skill("leg", me->query_int());
	return 1;
} 