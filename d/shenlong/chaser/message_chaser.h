// /d/shenlong/chaser/message_chaser.h
// Last Modified by winder on Jul. 12 2002
// this file only takes care those chasers or stealer to rob special stuff
void message_chaser()
{
	mapping owner_list;
	object *obj, ob, owner, rum_ob, *owners;
	object victim, chaser_ob, thief_ob, dest, room;
	string *names, filename, *filenames, file, chaser_file;
	int i, v_exp, temp;

	string *levels = ({
		"500000",
		"1000000",
	});

	remove_call_out("message_chaser");
//	call_out("message_chaser", 130 + random(100));
  //这个收集唯一物品很耗资源的
	call_out("message_chaser", 600 + random(100));

	filenames = keys(wanted_list);
	for(i = 0; i < sizeof(filenames); i++)
	{
		filename = filenames[i];
		obj = filter_array(children(filename), (: environment :));
		if( sizeof(obj) < 1 ) continue;
		ob = obj[random(sizeof(obj))];
		if( !(owner = environment(ob)) ) continue;
		if( ob->query("no_get")) continue;
		if( !living(owner) )
		{
			ob->move(this_object()); continue;
		}
		if( (string)owner->query("race") != "人类" )
		{
			ob->move(this_object()); continue;
		}
		if( owner->query("combat_exp") < 100000 && !userp(owner) && !owner->is_dealer() )
		{
			ob->move(this_object()); continue;
		}
		if( !userp(owner) && owner->query("no_fight") )
		{
			ob->move(this_object()); continue;
		}
			if( !userp(owner))
			{
				if (!owner->query("keep")) continue;
				if ((random(50)==1)	|| (ob->query("skill") && random(20)==1))
				{
					message("channel:snow",sprintf(HIM"【谣言】某人：听说%s"+HIM+"好象落在%s的%s"+HIM+"手里了！\n"NOR,
					ob->name(),
					to_chinese(explode(base_name(environment(owner)), "/")[1]),
					owner->name()),users());
				}
				continue;
			}
			else if (!wizardp(ob) && random(300)==1)
				message("channel:snow",sprintf(HIM"【谣言】某人：听说%s"+HIM+"好象落在%s"+HIM+"手里了！\n"NOR, 
				ob->name(),
				owner->query("name")),users());
		if( !userp(owner) ) continue;
		owner->add("unique_hold", 1);
		if( owner->query("unique_hold") > (int)owner->query("kar")*3 )
		{
			if( !mapp(owner_list) )
				owner_list = ([ owner: ob ]);
			else    owner_list[owner] = ob;
		}
	}
	if( !mapp(owner_list) ) return;
	owners = keys(owner_list);
	victim = owners[random(sizeof(owners))];
	if( !(dest = environment(victim)) ) return;
	ob = owner_list[victim];
	if( dest->query("no_fight") )
	{
		obj=filter_array(children(THIEF), (: environment :));
		if( !sizeof(obj) )
			thief_ob = new(THIEF);
		else
		{
			thief_ob = obj[0];
			if( !(room = environment(thief_ob)) )
			{
				destruct(thief_ob);
				return;
			}
			if( !living(thief_ob) || thief_ob->is_fighting() )
				return;
			if( dest == room ) return;
			message("vision", thief_ob->name() + "急急忙忙地离开了。\n", room, ({thief_ob}));
		}
		thief_ob->move(dest);
		message("vision", thief_ob->name() + "走了过来。\n", dest, ({thief_ob}));
		return;
	}
	victim->delete("unique_hold");
}

private int is_keeper(object ob, object obj)
{
	object env;
	string file, skill;
	string *no_keeper_list = ({
		"mu ren",
		"mengzhu",
		"shangshan shizhe",
		"fae shizhe",
		"feng qingyang",
		"guo xiang",
		"guo jing",
		"yideng dashi",
//		"ren woxing",
		"jin ren",
		"zhang men",
		"jiguan ren",
		"shi ren",
		"gongping zi",
	});

	if( !clonep(ob) || userp(ob) || ob->query("race") != "人类" ) return 0;
	if( !(env = environment(ob)) ) return 0;
	if( !env->query("exits") || env->query("no_fight") ) return 0;

	file = base_name(ob);
	if(  strsrch(file, "/d/xiakedao/") == 0 ||
		strsrch(file, "/u/") == 0 ||
		strsrch(file, "/kungfu/class/shenlong") == 0 ||
//		strsrch(file, "/d/huanghe/npc") == 0 ||
		strsrch(file, "/d/shenlong/npc") == 0 ) return 0;

	if( (int)ob->query("combat_exp") < 100000 ||
		(int)ob->query("combat_exp") > 800000 ||
		!living(ob) || ob->is_fighting() || ob->is_busy() ||
		member_array(ob->query("id"), no_keeper_list) != -1 )
		return 0;

	if( (skill = obj->query("skill_type")) )
	{
		if( (int)ob->query_skill(skill, 1) < 100 )
			return 0;
	}

	return 1;
}