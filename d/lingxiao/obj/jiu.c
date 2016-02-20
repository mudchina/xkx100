// Obj: /d/lingxiao/obj/jiu.c 参阳玉酒
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player()))
	{
		set("no_give","这么珍贵的酒，哪能随便给人？\n");
		set("no_drop","这么宝贵的美酒，扔了多可惜呀！\n");
		set("no_sell","这样的美酒都要卖,你太不解风情了吧。\n");
		set("no_put",1);
	}
	add_action("do_drink", "drink");
}

void create()
{
	set_name( YEL "参阳玉酒" NOR , ({"shenyang yujiu", "jiu"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "壶");
		set("long","一壶金黄的粘稠药酒，是凌霄城的珍藏，饮之于学武大有裨益。\n");
		set("value", 0);
		set("drug_type", "补品");
	}
	set("is_monitored",1);
	setup();
}

int do_drink(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");

	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("neili", (int)me->query("max_neili"));
	message_vision(HIW "$N举杯饮下参阳玉酒，只觉小腹间热气上冲，跟着胸口间便\n如火烧般热了起来，只觉通体融和，四骸俱泰。\n" NOR, me);
	destruct(this_object());
	return 1;
}

