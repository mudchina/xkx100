// pigdie.c

inherit ITEM;
void init()
{
	add_action("do_ge","ge");
	add_action("do_ge","cut");
}

void create()
{
	set_name("死猪", ({ "pig", "pigdie" }) );
	set("long", "这是一只死去的野猪，头部(zhutou)、前腿(forleg)、后腿(backleg)都
长得极为粗壮。\n");
	set_temp("zhutou", 1);
	set_temp("forleg", 1);
	set_temp("backleg", 1);
	set_weight(5000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("value", 300);
	}
	setup();
}

int do_get(string arg)
{
	object me=this_player();
	object ob=this_object();

	if( !arg ) return notify_fail("你要拿什么？\n");
	if( (string)arg=="pig")
	{
		if( me->query("str")<25 )
		{
			message_vision("这只野猪太沉了，你拿不动。\n", me);
			return 1;
		}
		message_vision("你扛起一整只猪，太沉了，真是受不了。\n", me);
		ob->move(me);
		return 0;
	}
}

int do_ge(string arg)
{
	object me=this_player();
	object ob;
	if(!arg||arg=="")
		return notify_fail("你要切什么东西？\n");
	if( (string)arg=="pig")
		return notify_fail("你要切哪一部分？\n");
	if( (!objectp(present("cut knife", me)) ))
	{
		message_vision("你没有合适的东西来切。有把菜刀或柴刀之类的就好了。\n", me);
		return 1;
	}

	switch( (string)arg)
	{
		case "zhutou" :
			if( query_temp("zhutou")==1)
			{
				message_vision("你砍下野猪的头。\n", me);
				ob=new(__DIR__"zhutou");
				ob->move(me);
				set_temp("zhutou" , 0);
				break;
			}
			else
			{
				message_vision("这野猪的头已被人砍走了。\n", me);
				return 1;
			}
		case "forleg" :
			if( query_temp("forleg")==1)
			{
				message_vision("你砍下野猪的前脚。\n", me);
				ob=new(__DIR__"forleg");
				ob->move(me);
				set_temp("forleg", 0);
				break;
			}
			else
			{
				message_vision("这野猪的前腿已被人砍走了。\n", me);
				return 1;
			}
		case "backleg" :
			if( query_temp("backleg")==1)
			{
				message_vision("你砍下野猪的后脚。\n",me);
				ob=new(__DIR__"backleg");
				ob->move(me);
				set_temp("backleg", 0);
				break;
			}
			else
			{
				message_vision("这野猪的后腿已被人砍走了。\n", me);
				return 1;
			}
	}
	if ((query_temp("zhutou")==0) &&
		(query_temp("forleg")==0) &&
		(query_temp("backleg")==0))
	{
		this_object()->move(environment(me));
		destruct(this_object());
	}
	return 1;
}

