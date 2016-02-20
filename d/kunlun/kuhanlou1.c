// Room: /d/kunlun/kuhanlou1.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "苦寒楼一层");
	set("long", @LONG
这里是苦寒楼的底层。苦寒楼结构简单，四周为浓密的云杉包围。
取名自“梅花香自苦寒来”之意，乃是昆仑派前辈为了激励后进昆仑派
弟子而建的，往上看，长长的木楼梯盘绕而上，似乎永无尽头。青砖地
相当洁净，看来经常有人打扫。四面墙上的壁画(bihua) 都是前辈们留
下武功图谱。
LONG );
	set("item_desc",([
		"bihua" : "壁画上人物的招式全是守御招法，绵绵不绝，妙不可言，引得你凝神揣摩(chuaimo)。\n",
	]));
	set("exits", ([
		"up"  : __DIR__"kuhanlou2",
		"out" : __DIR__"kuhanlou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -119980);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "up" ) me->set_temp("count", 1);
	else me->add_temp("count", -1);

	return ::valid_leave(me, dir);
}

int init()
{
	add_action("do_chuaimo","chuaimo");
}

int do_chuaimo(string arg)
{
	object me = this_player();
	if ( !living(this_player()) || arg != "parry" )
		return notify_fail("你要揣摩什么武功？\n");
	if ((int)me->query_skill("parry", 1) > 40)
		return notify_fail("壁画上所刻的武功你已全部领会了，不必再浪费时间了。\n");
	if ( me->query_skill("xuantian-wuji", 1)<30)
	{
		me->receive_damage("jing", 10);
		write("你本门内功实在太差，还是先休息一会吧！\n");
		return 1;
	}
	if ( (int)me->query("jing")<30)
	{
		me->receive_damage("jing", 10);
		write("你的琢磨的脑袋都大了，还是先休息一会吧！\n");
		return 1;
	}
	me->receive_damage("jing", random(25));
	message_vision("$N正在揣摩壁画上的武功。\n", me);
	write("你专心致志的揣摩壁画上的招式，感觉基本招架又进了一步。\n");
	me->improve_skill("parry", me->query_int());
	return 1;
} 