// tanzhu.h for join mingjiao 

int do_join(string arg)
{
	object me, ob, obj;
	mapping party;

	me = this_object () ;
	ob = this_player () ;

	if( !arg || arg!="mingjiao" )
		return notify_fail("你要加入什么组织？\n"); 
   	if( ob->query_temp("have_letter") || present("tuijian xin1", ob ))
   	{
                command("say 好啊。");
                command("heihei "+ob->query("id") );
//                command("get xin1 from "+ob->query("id") );
		return 1;	
	}
//	if (ob->query("weiwang")>49)
//	{
//		message_vision("$N摇摇头，对$n说道：你已经加入天地会了，不能再入我明教。\n",me,ob);
//		return 1;
//	}
//	if(ob->query("shenlongjiao")) 
//	{
//		message_vision("$N摇摇头，对$n说道：你已经加入神龙教了，不能再入我明教。\n",me,ob);
//		return 1;
//	}
   	if( !mapp(party = ob->query("party")) )
   	{
		message_vision("$N点点头，对$n说道：好，你到昆仑山总舵去找接引使者，他会让你入教的。\n",me,ob);
		message_vision("$N交给$n一封推荐信。\n", me, ob);
		ob->set_temp("have_letter",1);
                obj=new("/d/mingjiao/obj/tuijianxin-1");
		obj->move(ob);
		return 1;	
	}
   	if( party["party_name"] != HIG "明教" NOR )
	{
		message_vision("$N摇摇头，对$n说道：你已经加入其他帮会了，不能再入我明教。\n",me,ob);
		return 1;
	}
	else
		message_vision("$N摇摇头，对$n说道：你已经是我明教的人了。\n",me,ob);
	return 1;
}

#include "mingjiao.h"
