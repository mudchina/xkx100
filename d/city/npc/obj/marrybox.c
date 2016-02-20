//box.c 楠木雕花礼盒
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_open", "open");
}

void create()
{
	set_name(MAG"楠木雕花礼盒" NOR, ({"li he", "box"}));
	set("unit", "个");
	set("value", 50000);
	set("long", 
"这是「侠客行一百」飞雪堂专为新婚夫妇定做的礼盒，
楠木制的盒身，雕着精致的花纹，古色古香。\n");
	set("gift", 1);

	setup();
}

int do_open(string arg)
{
	object me,gift1;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="box"||arg=="li he")
	{
		if(query("gift") == 1)
		{
			message_vision(HIY "$N轻轻打开礼盒，眼前一亮：哇，好多喜糖，好好吃哦！\n" NOR, me);
			gift1 = new("/d/city/npc/obj/xitang");
			gift1->move(me);
			set("gift", 0);
			me->start_busy(1);
		}
		else message("vision",HIC"礼盒已经被人打开过了，里面空空的什么也没有。\n" NOR,me);
		return 1;
	}
}

void owner_is_killed()
{
	destruct(this_object());
}
