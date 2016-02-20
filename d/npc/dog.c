//dog.c

#include <ansi.h>
#include <command.h>

inherit NPC;

void create()
{
	set_name("小狗", ({ "dog" }) );
	set("title", "可怜的小东西");
	set("race", "走畜");
	set("gender", "雄性" );
	set("age", 10);
	set("str", 22);
	set("int", 30);
	set("dex", 30);
	set("con", 30);

	set("long", "你看到的是身陷泥淖的小狗。\n");
	set("combat_exp", 2000000);
	set("attitude", "friendly");

	set("max_qi", 10000);
	set("max_jing", 10000);
	set("inquiry", ([
		"参禅" : "找小和尚就知道了\n",
	]) );
	setup();
}

void init()
{
	object ob;

	::init();
	add_action("do_save","jiu");
	add_action("do_wei","wei");

	if ( interactive(ob = this_player()) && !is_fighting() )
	{
		 remove_call_out("wangwang");
		 call_out("wangwang", 1, ob);
	}
}

void wangwang(object ob)
{
	if (ob->query("id") == "solomon" )
		message_vision("小狗高兴地冲你直摇尾巴\n",ob);
	else
		message_vision("小狗悲伤地冲你汪汪两声\n",ob);
}

int do_save(string arg)
{
	this_player()->set("chanxin/save",1);
	message_vision("小狗高兴地冲你摇了两下尾巴\n",this_player());
	return 1;
}

int do_wei(string arg)
{
	if (this_player()->query("chanxin/save")>=1)
	{
		this_player()->set("chanxin/save",2);
		message_vision("小狗高兴地冲你摇了两下尾巴\n",this_player());
		return 1;
	}
	else
	{
		message_vision("小狗高兴地冲你摇了两下尾巴\n",this_player());
		return 1;
	}
}
