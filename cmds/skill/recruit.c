//recruit.c
// 增加升过袋的丐帮弟子不能投别派。
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	object ob, old_rec;
	mapping family;
	int i,fealty;
	string temp;
	int student_num;
	object feng,room;
	int flag;

	if (!arg)
		return notify_fail("指令格式：recruit|shou [cancel]|<对象>\n");
	if (arg=="cancel")
	{
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("你现在并没有收录任何人为弟子的意思。\n");
		write("你改变主意不想收" + old_rec->name() + "为弟子了。\n");
		tell_object(old_rec, me->name()+"改变主意不想收你为弟子了。\n");
		me->delete_temp("pending/recruit");
		return 1;
	}
          if(arg=="corpse"||arg=="skeleton")
           	return notify_fail("看清楚一点，那并不是生物。\n");
//        if(!living(ob)||ob->query_temp("noliving"))
//              return notify_fail("看清楚一点，那不是人。\n");

	if (!(ob=present(arg,environment(me))))
		return notify_fail("你想收谁作弟子？\n");
	if (ob==me)
		return notify_fail("收自己为弟子？好主意....不过没有用。\n");
	if (ob->is_apprentice_of(me))
	{
		message_vision("$N拍拍$n的头，说道：「好徒儿！」\n", me, ob);
		return 1;
	}
	if (!me->query("family"))
		return notify_fail("你并不属于任何门派，你必须先加入一个门派，或自己创一个才能收徒。\n");
	if( ob->query("party") &&
		ob->query("party/party_name") == HIC"丐帮"NOR &&
		me->query("family/family_name") != "丐帮")
	{
		message_vision("$N看了看$n，摇了摇头道：「你是丐帮有袋弟子，还是回丐帮去吧。」\n", me, ob);
		return 1;
	}
	if (me->accept_betrayer(ob))
	{
		message_vision("$N看了看$n，忽然又摇了摇头道：「你生性反复，无缘承接本门衣钵，好自为之吧。」\n", me, ob);
		return 1;
	}
// If the target is willing to apprentice us already, we do it.
	if ((object)ob->query_temp("pending/apprentice") == me)
	{
  	if (ob->query("detach/"+me->query("family/family_name"))>0)
  	{
		message_vision("$N看了看$n，摇了摇头道：「你当年既然离开了"+me->query("family/family_name")+"，今天又何必回来？」\n", me, ob);
		return 1;
		}
		if (!living(ob) || ob->query_temp("noliving") )
		{
			message_vision("$N决定收$n为弟子。\n\n不过看样子$n显然没有办法行拜师之礼。\n\n",me, ob);
			return 1;
		}
// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
		if((ob->query("family")) && (me->query("family")) &&
			( (string)me->query("family/family_name") !=
			(string)ob->query("family/family_name") ) )
		{
// Modified by That Oct.17 1997
			if (ob->query("title")=="隐士" ||ob->query("combat_exp")<100000) 
			{
   	    ob->add("detach/"+ob->query("family/family_name"),1);
				message_vision("$N决定屈尊投入$n门下！！\n\n$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n$N心里却大叫辣块妈妈！\n\n", ob, me);
				ob->set_temp("fealty_temp",0);
				ob->set("score", 0);
				ob->add("betrayer", 1);
		    ob->delete("perform");		
			}
			else
			{
				message_vision("$N拍了拍$n的脑门：怪！经验这么高！嘿嘿，我可不敢收你了。\n", me, ob);
				return 1;
			}
		}
		else
		{
			message_vision("$N决定收$n为弟子。\n\n$n跪了下来向$N恭恭敬敬地磕了四个响头，叫道：「师父！」\n", me, ob);
 		}
		if ((string)ob->query("family/master_id")=="feng qingyang")
		{
			room = find_object("/d/huashan/xiaofang");
			if (!objectp(room)) room = load_object("/d/huashan/xiaofang");
			feng = present("feng qingyang",room);
			if (!objectp(feng)) 
			{
				feng = new("/kungfu/class/huashan/feng");
				flag = 1;
			}
			feng->delete("students/"+ob->query("id"));
			feng->set("no_accept/"+ob->query("id"),1);
			feng->save_data();
			if (flag == 1) destruct(feng);
		}
		me->recruit_apprentice(ob);
		ob->delete_temp("pending/apprentice");
		fealty=(int)(ob->query_temp("fealty_temp"));
		ob->set("family/fealty",fealty);
		ob->delete_temp("fealty_temp");

		if ((ob->query("class")!="bonze") &&
			(me->query("class")!="bonze") &&
			(ob->query("class")!="lama") &&
			(me->query("class")!="lama") &&
			(ob->query("class")!="quanzhen") &&
			(me->query("class")!="quanzhen") &&
			(ob->query("class")!="eunach") &&
			(me->query("class")!="eunach"))
			ob->set("class",me->query("class"));
	
		write("恭喜你新收了一名弟子！\n");
		family = ob->query("family");
		tell_object( ob, sprintf("恭喜您成为%s的第%s代弟子。\n", family["family_name"], chinese_number(family["generation"]) ));
		return 1;
	}
	else
	{
		old_rec = me->query_temp("pending/recruit");
		if( ob==old_rec )
		return notify_fail("你想收" + ob->name() + "为弟子，但是对方还没有答应。\n");
		else if( objectp(old_rec) )
			{
				write("你改变主意不想收"+old_rec->name()+"为弟子了。\n");
				tell_object(old_rec,me->name()+"改变主意不想收你为弟子了。\n");
			}
		me->set_temp("pending/recruit", ob );
		message_vision("\n$N想要收$n为弟子。\n", me, ob);
		tell_object(ob, YEL "如果你愿意拜" + me->name() + "为师父，用 apprentice 指令。\n" NOR);
		return 1;
	}
}


int help(object me)
{
	write(@HELP
指令格式 : recruit|shou [cancel]|<对象>

    这个指令能让你收某人为弟子，如果对方也答应要拜你为师的话。

See Also: apprentice
HELP
	);
	return 1;
}
