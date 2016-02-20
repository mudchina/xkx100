// laoban.c 
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("老板娘", ({"laoban niang", "laoban"}));
	set("age", 32);
	set("gender", "女性");
	set("per", 20);
	set("attitude", "friendly");

	set("combat_exp", 400);
	set_skill("unarmed", 10);
	set_skill("dodge", 10);

	set("vendor_goods", ({
		__DIR__"obj/meigui",
		__DIR__"obj/mudan",
		__DIR__"obj/chahua",
		__DIR__"obj/lanhua",
		__DIR__"obj/meihua",
		__DIR__"obj/redrose",
		__DIR__"obj/yaohuang",
		__DIR__"obj/weizi",
	}));
	set("chat_chance", 20);
	set("chat_msg", ({
		"老板娘叹道：人如同花一般，一天不如一天了。\n",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 2);
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_send", "send");
}
int do_send(string arg)
{
	object obj, flower, me = this_player();
	string target, item;

	if(!arg) return notify_fail("老板娘说：你要给谁什么东西？\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	if( sscanf(arg, "%s to %s", item, target) !=2)
		return notify_fail("老板娘说：你要给谁什么东西？\n");

	obj = find_player(target);
		if(!obj || !me->visible(obj))
			return notify_fail("老板娘说：此人现在不在。没法帮你送花。\n");

	if( !living(obj))
		return notify_fail("老板娘说：抱歉，现在没法帮你送花。\n");

	if( !objectp(flower = present(item, me)) )	
		return notify_fail("老板娘说：你身上没有这种花。\n");

	if( !flower->query("flower"))
		return notify_fail("老板娘说：你只能让我帮你送花。\n");

	if( flower->query("no_drop") )
		return notify_fail("这样东西不能随便给人。\n");

	flower->move(obj);
	me->save();
	obj->save();
	tell_object(me, HIC"花店老板娘笑了笑道：“这位"+RANK_D->query_respect(me)+"稍候，这就给你送到"+obj->query("name")+"手上。”转身出门去了。\n" NOR );
	tell_object(obj, HIC"花店老板娘走过来递给你一"+flower->query("unit")+flower->query("name")+HIC"，轻轻说道：“这是"+me->query("name")+"送给你的。”转身笑了笑就走了。\n" NOR );
	tell_object(me, HIC"花店老板娘片刻后回来笑道：“放心吧，送到了。”\n" NOR );
	return 1;
}
