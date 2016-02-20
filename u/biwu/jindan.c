// /d/city/obj/bing6.c 状元饼

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY "九转金丹" NOR, ({ "jiuzhuan jindan", "dan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "颗");
		set("long", "一颗金色的仙丹，传说是太上老君精心修炼的灵丹妙药。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_put", 1);
		set("no_beg", 1);
		set("no_steal", 1);
	}
	setup();
}

int do_eat(string arg)
{
	int i;
	object me=this_player();
	object ob=this_object();
	int effect = 0;
	
	if (!id(arg))  return notify_fail("你要吃什么？\n");
		message_vision(HIY "$N一仰脖，吞下一"+ob->query("unit")+"$n。\n" NOR, me,ob);

// 臂力
	if (me->query("gift/str/all") < 10 && me->query("str") < 35 && random(2))
	{
		effect++;
//		write(HIG "你觉得自己的膂力更强健了。\n" NOR);
		write(HIG "你的膂力增加了。\n" NOR);
		me->add("gift/str/succeed",1);
		me->add("gift/str/all", 1);
		me->add("str", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s 吃下%-10s增加了%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "臂力","str",ctime(time())));
	}
// 根骨
	if (me->query("gift/con/all") < 10 && me->query("con") < 35 && random(2))
	{
		effect++;
//		write(HIC "你觉得自己的内息更通畅了。\n" NOR);
		write(HIC "你的根骨增加了。\n" NOR);
		me->add("gift/con/succeed",1);
		me->add("gift/con/all", 1);
		me->add("con", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s 吃下%-10s增加了%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "根骨","con",ctime(time())));
	}

//身法
	if (me->query("gift/dex/all") < 10 && me->query("dex") < 35 && random(2))
	{
		effect++;
//		write(HIR "你觉得自己的腿脚更灵活了。\n" NOR);
		write(HIR "你的身法增加了。\n" NOR);
		me->add("gift/dex/succeed",1);
		me->add("gift/dex/all", 1);
		me->add("dex", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s 吃下%-10s增加了%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "身法","dex",ctime(time())));
	}	
// 福缘
	if (me->query("gift/kar/all") < 10 && me->query("kar") < 35 && random(2))
	{
		effect++;
		write("你的福缘提高了。\n" NOR);
		me->add("gift/kar/succeed",1);
		me->add("gift/kar/all", 1);
		me->add("kar", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s 吃下%-10s增加了%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "福缘","kar",ctime(time())));
	}
// 胆识
	if (me->query("gift/cor/all") < 10 && me->query("cor") < 35 && random(2))
	{
		effect++;
		write("你的胆识提高了。\n" NOR);
		me->add("gift/cor/succeed",1);
		me->add("gift/cor/all", 1);
		me->add("cor", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s 吃下%-10s增加了%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "胆识","cor",ctime(time())));
	}

// 定力
	if (me->query("gift/cps/all") < 10 && me->query("cps") < 35 && random(2))
	{
		effect++;
		write("你的定力提高了。\n" NOR);
		me->add("gift/cps/succeed",1);
		me->add("gift/cps/all", 1);
		me->add("cps", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s 吃下%-10s增加了%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "定力","cps",ctime(time())));
	}
// 灵性
	if (me->query("gift/spi/all") < 10 && me->query("spi") < 35 && random(2))
	{
		effect++;
		write("你的灵性提高了。\n" NOR);
		me->add("gift/spi/succeed",1);
		me->add("gift/spi/all", 1);
		me->add("spi", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s 吃下%-10s增加了%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "灵性","spi",ctime(time())));
	}
// 耐力
	if (me->query("gift/sta/all") < 10 && me->query("sta") < 35 && random(2))
	{
		effect++;
		write("你的耐力提高了。\n" NOR);
		me->add("gift/sta/succeed",1);
		me->add("gift/sta/all", 1);
		me->add("sta", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s 吃下%-10s增加了%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "耐力","sta",ctime(time())));
	}
// 容貌
	if (me->query("gift/per/all") < 10 && me->query("per") < 35 && random(2))
	{
		effect++;
		write("你的容貌提高了。\n" NOR);
		me->add("gift/per/succeed",1);
		me->add("gift/per/all", 1);
		me->add("per", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s 吃下%-10s增加了%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "容貌","per",ctime(time())));
	}
	if (! effect)
		tell_object(me, "不过你觉得好像没什么作用。\n");
		destruct(this_object());
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}

