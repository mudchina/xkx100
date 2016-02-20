// Room: /heizhao/shanlu5.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "泥沼");
	set("long", @LONG
“啊哟”一声，你的双足已陷入泥中，直没至漆，你急忙提气
后跃，硬生生把两只脚拔了出来，一股污泥的臭味极是刺鼻。向前
望去，眼前一团茫茫白雾裹着两间茅屋 (house)，灯光便从茅屋中
射出。
LONG );
	set("outdoors", "heizhao");
	set("no_clean_up", 0);
	set("item_desc", ([
		"house" : "茅屋一方一圆，建在污泥湖沼之中，四周无处落脚。看来
你只好跳进去了。\n",
	]));
	set("exits", ([
		"southwest"  : __DIR__"shanlu4",
	]));
	set("coor/x", -5100);
	set("coor/y", -1500);
	set("coor/z", -5);
	setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me=this_player();

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	if( !arg || (arg != "left" && arg != "right"))
		return notify_fail("你要往左跳还是往右跳啊？\n");
	message_vision(HIY "$N劲发足跟，高高跃起，跃墙而过！\n"NOR,me);

	if (random(me->query_skill("dodge",1)) < 60)
	{
message_vision(HIR"结果只听一声闷哼，$N还没跃到墙头就掉在泥沼里了...\n"NOR,me);
message_vision(HIB"屋里伸出一只女人的手，提起$N的衣领，一抛就抛出林外去了。\n"NOR,me);
		me->receive_damage("qi", 100);
		me->start_busy(random(50));
		me->move(__DIR__"shanlu1");
		return 1;
	}
	if (arg == "right")
	{
message_vision(HIC"只听一声轰响，真是帅呆了，$N正掉在水塘里！\n"NOR,me);
message_vision(HIB"屋里伸出一只女人的手，提起$N的衣领，一抛就抛出林外去了。\n"NOR,me);
		me->receive_wound("qi", 200);
		me->receive_damage("qi", 200);
		me->start_busy(random(20));
		me->move(__DIR__"shanlu1");
		return 1;
	}
message_vision(HIY"$N越过高墙，落在院子左首实地上。\n"NOR,me);
	me->move(__DIR__"hzyuanzi");
	return 1;
}