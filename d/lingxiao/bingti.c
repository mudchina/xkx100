// Room: /d/lingxiao/bingti.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "冰梯");
	set("long", @LONG
这里是一座晶莹剔透的冰梯。此处地处万里雪山顶峰，连接凌霄城
的天险防线分天崖。悬在这里，只觉罡风凛冽，如利刃割体，身侧寒云
渺渺，白烟氤氲。桥下万载寒冰，在日光下闪烁生辉。山寒水冷，众鸟
飞尽，惟有朵朵白雪，依旧飘零。这里往往有伤心失意人跳崖自尽。
LONG );
	set("exits", ([
		"up"   : __DIR__"yuan",
		"down" : __DIR__"fentianya",
	]));
	set("outdoors", "lingxiao");
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8940);
	set("coor/z", 130);
	setup();
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(object me)
{
	me = this_player();
	message_vision("$N看了看脚下悠悠白云，一咬牙，眼一闭，纵身往冰桥下跳去\n", me);
	if (me->query_dex()>25)
	{
		me->move(__DIR__"juegu");
	}
	else if (me->query_dex()>20)
	{
		me->move(__DIR__"boot");
		me->unconcious();
	}
	else
	{
		me->move(__DIR__"juegu");
		me->die();
	}
	return 1;
}

