// yaopai.c

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
	set_name("腰牌", ({ "yao pai", "yaopai" }));
	set("long", "这是一块帮会的腰牌。\n"+
"    凭此腰牌，可以提升(tisheng) 和降黜(jiangchu)本帮会内所有
下属人众，甚至将其驱逐(quzhu) 出帮会。被驱逐者损失一定存款和
阅历。如果对本帮会十分失望，可以自行退出(tuichu)所属帮会，代
价一定的存款和阅历。
     帮(门、教)主无法退会。但可以让位(rangwei) 给本帮会众，
功成身退。对于违命背叛的下属，可以限时派出本帮会刑堂的执法弟
子前往惩处(chengchu)。
    如果想提升一位非本帮会人员成为本帮一般人众，被提升者为表
示忠诚之决心，必须先割一个脑袋瓜来作为加盟投名状。
    所有入会人等均能获得一块腰牌，并按自己的权限凭腰牌行使上
述权力。
      教(帮、门)主    提升 降黜 惩处 驱逐 任命 创立 让位
      副教(帮、门)主  提升 降黜 惩处 驱逐 退出
      长老            提升 降黜 惩处 退出
      香主            提升 降黜 退出
      旗主            退出
      一般人众        退出
其中第三、四、五阶层人等可以任命(renming)专名。如传功长老、
红旗香主、风云旗主等等。任何人等均可用party命令查阅本帮会名
单。
    如果不幸丢失本腰牌，可以到关林对着关夫子像猛磕头(ketou)，
好好思过。
\n");
	set("weight", 300);
	set("no_get", 1);
	set("no_get_from", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("value", 1);
		set("material", "玉");
	}
	setup();
	init_dagger(5);
}

void init()
{
	add_action("do_tisheng","tisheng");
	add_action("do_jiangchu","jiangchu");
	add_action("do_renming","renming");
	add_action("do_quzhu","quzhu");
	add_action("do_tuichu","tuichu");
	add_action("do_chengchu","chengchu");
	add_action("do_rangwei","rangwei");
}

int do_tisheng(string arg)
{
	object where, ob, pai, me = this_player();
	string partynm;
	int i, mylvl, oblvl;

	if(!arg) return notify_fail("你要提升谁的职司？\n");
	if(!me->query("party"))
		return notify_fail("你不属于任何帮会！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家创立的帮会才能使用腰牌！\n");
	where = environment(me);
	if ((string)where->query("short")!="关林")
		return notify_fail("只能在关帝林中才能提升职司！\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("这里没有这个人。\n");
	if(ob == me) return notify_fail("真是聪明的方法。\n");
	if(!userp(ob))
		return notify_fail("你只能提升玩家。\n");
	partynm = me->query("party/party_name");
	i = strlen(partynm);
	mylvl = me->query("party/level");
	if (mylvl > 5) return notify_fail("你无权提升任何人。\n");
	if(!ob->query("party"))
	{
		if(me->query_temp("party/toumingzhuang") != ob->query("id"))
			return notify_fail("对方要先给你个人头作投名状，然后你才能接引人家。\n");
		ob->set("party/party_name", partynm);
		ob->set("party/rank", "一般人众");
		ob->set("party/player", 1);
		ob->set("party/level", 6);
		ob->set("party/enter_time", time());
		pai=new(__DIR__"yaopai");
		pai->move(ob);
		message_vision("$N获得一块腰牌！\n", ob);
		message("channel:chat", HIR"【通告】"+ob->query("name")+"于"+NATURE_D->game_time()+"由"HIG+me->query("party/rank")+me->query("name")+HIR"接引，加入"+partynm+"！\n"NOR,users());
		return 1;
	}

	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是别的帮会的耶！\n");
	oblvl = ob->query("party/level");
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"的职司不比你低，你忙乎个啥劲呀！\n");
	if(oblvl - mylvl == 1)
		return notify_fail("只能提升对方成为你的下属。\n");

	ob->set("party/level", oblvl - 1);
	switch (oblvl)
	{
		case 3: ob->set("party/rank", "副"+partynm[i-2..i]+"主"); break;
		case 4: ob->set("party/rank", "长老"); break;
		case 5: ob->set("party/rank", "香主"); break;
		case 6: ob->set("party/rank", "旗主"); break;
	}
	message_vision("$N冲着关帝像俯身下去，恭恭敬敬磕了三响头！\n", ob);
	message("channel:chat", HIR"【通告】"HIY+ob->query("name")+"于"+NATURE_D->game_time()+"被"HIG+me->query("party/rank")+me->query("name")+HIY"提升为"+partynm+ob->query("party/rank")+"！\n"NOR, users());
	return 1;
}

int do_jiangchu(string arg)
{
	object ob, me = this_player();
	string partynm;
	int i, mylvl, oblvl;

	if(!arg) return notify_fail("你要降黜谁的职司？\n");
	if(!me->query("party"))
		return notify_fail("你不属于任何帮会！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家创立的帮会才能使用腰牌！\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("这里没有这个人。\n");
	if(ob == me) return notify_fail("真是聪明的方法。\n");

	partynm = me->query("party/party_name");
	i = strlen(partynm);
	mylvl = me->query("party/level");
	if (mylvl > 5) return notify_fail("你无权降黜任何人。\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"好象没加入什么帮会耶！\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是别的帮会的耶！\n");
	oblvl = ob->query("party/level");
	if(oblvl == 6)
		return notify_fail(ob->query("name")+"的职司已经没法降了，想惩罚只有驱逐出去了！\n");
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"的职司不比你低，你想犯上？\n");
	ob->set("party/level", oblvl + 1);
	switch (oblvl)
	{
		case 2: ob->set("party/rank", "长老"); break;
		case 3: ob->set("party/rank", "香主"); break;
		case 4: ob->set("party/rank", "旗主"); break;
		case 5: ob->set("party/rank", "一般人众"); break;
	}
	message("channel:chat", HIR"【通告】"HIY+ob->query("name")+"于"+NATURE_D->game_time()+"被"HIG+me->query("party/rank")+me->query("name")+HIY"降黜为"+partynm+ob->query("party/rank")+"！\n"NOR, users());
	return 1;
}

int do_renming(string arg)
{
	object where, ob, pai, me = this_player();
	string obname, rankname, partynm;
	int i, mylvl, oblvl;

	if(!arg) return notify_fail("你要任命谁的职司？\n");
	if(!me->query("party"))
		return notify_fail("你不属于任何帮会！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家创立的帮会才能使用腰牌！\n");
	where = environment(me);
	if ((string)where->query("short")!="关林")
		return notify_fail("只能在关帝林中才能任命职司！\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	if( sscanf(arg, "%s to %s", obname, rankname) !=2)
		return notify_fail("renming 谁 to 专名\n");
	if(!objectp(ob = present(obname, environment(me))) || !living(ob))
		return notify_fail("这里没有这个人。\n");
	if(ob == me) return notify_fail("真是聪明的方法。\n");

	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl > 1)
		return notify_fail("只有最高首领才能任命专名！\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"没有加入任何帮会，你任命个啥劲哪！\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是别的帮会的耶！\n");
	i = strlen(rankname);
	if( (strlen(rankname) < 4) || (strlen(rankname) > 6 ) )
	{
		return notify_fail("对不起，任命名称必须是两三个中文字。\n");
	}
	while(i--)
	{
		if( rankname[i]<=' ' )
		{
			return notify_fail("任命名称不能用控制字元。\n");
		}
		if( i%2==0 && !is_chinese(rankname[i..<0]) )
		{
			return notify_fail("任命名称必须是「中文」。\n");
		}
	}

	oblvl = ob->query("party/level");
	switch (oblvl)
	{
		case 3: ob->set("party/rank", rankname+"长老"); break;
		case 4: ob->set("party/rank", rankname+"香主"); break;
		case 5: ob->set("party/rank", rankname+"旗主"); break;
		default: return notify_fail(ob->query("name")+"的职司不能任命专名！\n");
	}
	message_vision("$N冲着关帝像俯身下去，恭恭敬敬磕了三响头！\n", ob);
	message("channel:chat", HIR"【通告】"HIY+ob->query("name")+"于"+NATURE_D->game_time()+"被"+me->query("name")+"任命为"+partynm+ob->query("party/rank")+"！\n"NOR, users());
	return 1;
}

int do_quzhu(string arg)
{
	object *inv, pai, ob, me = this_player();
	string partynm;
	int i, j, mylvl, oblvl;

	if(!arg) return notify_fail("你要驱逐谁？\n");
	if(!me->query("party"))
		return notify_fail("你不属于任何帮会！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家创立的帮会才能使用腰牌！\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("这里没有这个人。\n");
	if(ob == me) return notify_fail("真是聪明的方法。\n");

	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl > 2)
		return notify_fail("你没有权力驱逐别人。\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"没有加入任何帮会，你驱逐个啥劲哪！\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是别的帮会的耶！\n");
	oblvl = ob->query("party/level");
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"的职司不比你低，你想干嘛！\n");
	ob->delete("party");
	inv = all_inventory(ob);
	i = sizeof(inv);
	for (j = 0; j < i; j++)
	{
		if(inv[j]->query("id") == "yao pai") destruct(inv[j]);
	}
//	ob->set("combat_exp", ob->query("combat_exp")*99/100);
	if ((int) ob->query("balance")>0 )
	   ob->set("balance",ob->query("balance")*99/100);
	ob->set("score", ob->query("score")*99/100);	   
	message_vision("$N从$n身上收回一块腰牌！\n", me, ob);
	message("channel:chat", HIR"【通告】"HIY+ob->query("name")+"于"+NATURE_D->game_time()+"被"HIG+me->query("party/rank")+me->query("name")+HIY"驱逐出"+partynm+"！以后此人所为，与"+partynm+"无涉！\n"NOR, users());
	return 1;
}

int do_tuichu()
{
	object *inv, pai, me = this_player();
	string partynm;
	int i, j, mylvl;

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	if(!me->query("party"))
		return notify_fail("你没有加入任何帮会，看你还能往哪退吧！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家创立的帮会才能使用腰牌！\n");
	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl == 1)
		return notify_fail(partynm+"是你手创，你怎么能退出呢！\n");
	me->delete("party");
//	me->set("combat_exp", me->query("combat_exp")*98/100);
	if ((int) me->query("balance")>0 )
	   me->set("balance",me->query("balance")*98/100);
	me->set("score", (int)me->query("score")*98/100);
	message_vision("$N取出腰牌，狠狠砸碎在地上，以示决裂！\n", me);
	message("channel:chat", HIR"【通告】"HIY+me->query("name")+"："+RANK_D->query_self_rude(me)+"已于"+NATURE_D->game_time()+"自愿退出"+partynm+"！以后"+partynm+"一切所为，与"+RANK_D->query_self_rude(me)+"一概无涉！\n"NOR, users());
	destruct(this_object());
	return 1;
}

int do_chengchu(string arg)
{
	object where, killer, ob, me = this_player();
	string partynm;
	int mylvl, oblvl, obskill;

	if(!arg) return notify_fail("你要惩处谁？\n");
	if(!me->query("party"))
		return notify_fail("你不属于任何帮会！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家创立的帮会才能使用腰牌！\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(me->query("party/chengchu") + 3600 > time())
		return notify_fail(partynm+"执法弟子不在刑堂，无法派出！\n");
	if(mylvl > 3)
		return notify_fail("你没有权力惩处别人。\n");
	ob = find_player(arg);
	if(!ob) return notify_fail("你要惩处的人不在江湖中。\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"没有加入任何帮会，你惩处个啥劲哪！\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是别的帮会的耶！\n");
	oblvl = ob->query("party/level");
	obskill = ob->query_skill("parry",1);
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"的职司不比你低，你想和人家玩可不成啊！\n");
	where = environment(ob);

	killer = new("/d/luoyang/npc/zhifa");
	killer->set("target", ob->query("id"));
	killer->set("owner", me->query("name"));
	killer->set("party/party_name", partynm);
	killer->set("party/rank", HIC"刑堂"NOR);
	killer->set("combat_exp", ob->query("combat_exp") * 3 / 2);
	killer->set_skill("unarmed", obskill);
	killer->set_skill("parry", obskill);
	killer->set_skill("sword", obskill);
	killer->set_skill("dodge", obskill);
	killer->set_skill("force", obskill);
	killer->set_skill("taiji-shengong", obskill);
	killer->set_skill("taiji-quan", obskill);
	killer->set_skill("taiji-jian", obskill);
	killer->set_skill("liangyi-jian", obskill);
	killer->set_skill("tiyunzong", obskill);
	killer->map_skill("force", "taiji-shengong");
	killer->map_skill("unarmed", "taiji-quan");
	killer->map_skill("parry", "taiji-jian");
	killer->map_skill("sword", "liangyi-jian");
	killer->map_skill("dodge", "tiyunzong");
	killer->move(where);

	me->set("party/chengchu", time());
        tell_room(where, killer->query("name")+"走了过来。\n", ({killer}));
	return notify_fail("已经派出执法弟子前往"+ob->query("name")+"所在之处了！\n");
}
int do_rangwei(string arg)
{
	object *inv, pai, ob, me = this_player();
	string partynm;
	int i, j, mylvl, oblvl;

	if(!arg) return notify_fail("你要让位给谁？\n");
	if(!me->query("party"))
		return notify_fail("你不属于任何帮会！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家创立的帮会才能使用腰牌！\n");
	if(me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("这里没有这个人。\n");
	if(ob == me) return notify_fail("真是聪明的方法。\n");

	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl > 1)
		return notify_fail("你这个职份让什么位！臭显啊！\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"没有加入任何帮会，你让不成位啦！\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是别的帮会的耶！\n");
	if(ob->query("age") < 50 || ob->query("combat_exp") < 5000000)
		return notify_fail(ob->query("name")+"好象嫩得很，不足担此大任！\n");
	ob->set("party/level", 1);
	ob->set("party/rank", me->query("party/rank"));
	message_vision("$N向$n交回一块腰牌！\n", me, ob);
	message("channel:chat", HIR"【通告】"HIY+me->query("name")+"："+RANK_D->query_self(me)+"于"+NATURE_D->game_time()+"将"HIG+partynm+me->query("party/rank")+HIY"之位让予"+ob->query("name")+"！望各位江湖同道捧场！"HIR"恭喜新"+me->query("party/rank")+"！\n"NOR, users());
	me->delete("party");
	inv = all_inventory(me);
	i = sizeof(inv);
	for (j = 0; j < i; j++)
	{
		if(inv[j]->query("id") == "yao pai") destruct(inv[j]);
	}
	return 1;
}
 
string query_autoload()
{
	return 1 + "";
}
void owner_is_killed()
{
	destruct(this_object());
}

