// finit.h
#include <ansi.h>
#define A_TIME 60

string * weapon_msg = ({
	"/d/city/task2/obj/anqi",
	"/d/city/task2/obj/anqi",
	"/d/city/task2/obj/anqi",
	"/d/city/task2/obj/anqi",
	"/d/city/task2/obj/anqi",
	"/d/city/task2/obj/anqi",
	"/d/city/task2/obj/chuidutong",
	"/d/city/task2/obj/sheerkou",
});

void init()
{
	remove_call_out("do_check");
	call_out("do_check", 0);
	remove_call_out("do_wait");
	call_out("do_wait",A_TIME);
}

void do_check()
{
	object me = this_object();
	object ob;

	if (! living(me) || me->fighting() )
	{
		remove_call_out("do_check");
		call_out("do_check",0);
	}
	else
	{
		if( !ob = present("biao tou",environment(me)))
		{
			remove_call_out("do_check");
		        call_out("do_check",0);
		}
		else
		{
			command("shot "+ob->query("id"));
			ob -> add("combat_num",1);
			message_vision(HIW"\n$N大喊道：保镖的兔崽子，纳命来吧！\n"NOR,me);
			remove_call_out("do_sha");
			call_out("do_sha",1);
		}
	}
}

void do_wait()
{
	object ob;
	object me = this_object();

	if (me->is_fighting() || !living(me) )
	{
		remove_call_out("do_wait");
		call_out("do_wait",A_TIME);
	}
	else
	{
		message_vision("$N说道：风紧！风紧！大爷先走了！\n$N一阵哄向远处逃了开去。\n",this_object());
		destruct(me);
	}
}

void do_sha()
{
	object me = this_object();
	object cart,ob, weapon;
	string wmsg;

	if (! living(me) || me->fighting() )
	{
		message_vision("$N咬牙切齿地对着天空大叫：“贼老天！”\n",me);
		remove_call_out("do_sha");
		call_out("do_sha",0);
	}
	else
	{
		if( ob = present("biao tou",environment(me)))
		{
			wmsg = weapon_msg[random(sizeof(weapon_msg))];
			weapon = new(wmsg);
			weapon->move(me);
			message_vision(HIW"\n$N冲着$n大喊道：你还不死！！看我的手段！\n"NOR,me, ob);
			command("shot "+ob->query("id"));
			ob -> add("combat_num",1);
			remove_call_out("do_sha");
			call_out("do_sha",0);
		}
		else
		{
			message_vision("$N说道：大功告成！大爷先走了！\n$N一阵大哄向远处飞驰而去。\n",me);
			if ( cart = present("cart",environment(me)))
                        destruct(cart);         
                        destruct(me);
		}
	}
}

