// /d/hangzhou/npc/hongniang.c

// Modified by Constant Jan 11 2001

#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
	set_name("红娘", ({ "hong niang","hong" }) );
	set("title", "红娘庄");
	set("gender", "女性" );
	set("age", 16);
	set("long",
		"一位明眸皓齿的小姑娘。\n");
	set("max_qi",800);
	set("max_jing",800);
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("inquiry", ([
		"婚约" : "是啊……这里就可以缔结(marry)和解除婚约(unmarry)。",
		"结婚" : "是啊……这里就可以缔结(marry)和解除婚约(unmarry)。",
		"成亲" : "是啊……这里就可以缔结(marry)和解除婚约(unmarry)。",
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 200);
	set_skill("unarmed", 100);
	setup();
	add_money("gold", 10);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	add_action("do_marry", "marry");
	add_action("do_unmarry", "unmarry");
}

int do_marry(string arg)
{
	object marry_card1,marry_card2, obj, me;
	object *list,ob;
	int i, have_marry;
	me = this_player();
	list = all_inventory(me);
	i = sizeof(list);
	have_marry = 0;

	if(me->query("couple/times") > 2)
	{
		say("红娘笑道: 你都结了几次婚了，还来玩弄别人家的感情？\n");
		return 1;
	}
	if(me->query("couple/times") > 1)
	{
		say("红娘笑道: 来我这的都是少男少女，你可是这里的老常客啦。红娘我也不能老替你做伐。这可是最后一次了。\n");
	}
	if((string)me->query("gender")=="无性")
	{
		say("红娘笑道: 这位公公，你这不是开玩笑么？\n");
		return 1;
	}
	if ( (string)me->query("class")=="bonze")
		return notify_fail("红娘笑骂道: 你是出家人，结什么婚！你以为你是不戒和尚啊。\n");
	if ( (int)me->query("age")<17)
		return notify_fail("红娘笑道: 你还小，等到十七岁再来吧。\n");
	if ( me->query("couple/couple_id"))
		return notify_fail("红娘板着脸道: 你已经结婚了吧？\n");
	if(!arg || !objectp(obj = present(arg, environment(me)))
		|| !find_player(arg)|| !find_living(arg))
	return notify_fail("红娘笑道: 你想和谁缔结良缘？\n");
	if( !environment() || base_name(environment()) != query("startroom") )
		return notify_fail("红娘笑道: 真是抱歉，请您等一下到红娘庄来找我吧。\n");
	if( !living(obj) )
		return notify_fail("红娘叹口气对你说道: "+obj->name()+"已经无法和你缔结良缘了。\n");
	if( obj->query("couple/couple_id"))
		return notify_fail("红娘笑了起来: 人家已经结婚了吧？\n");
	if( obj->query("couple/times") > 2)
		return notify_fail("红娘嘿嘿冷笑了几声: 人家都结了几次婚了，是来玩弄你的感情来着。\n");
	if(obj==me)
		return notify_fail("红娘笑道: 和自己缔结婚约？你有病啊！\n");
	if((string)obj->query("gender")== (string)me->query("gender"))
		return notify_fail("红娘笑道: 同性恋？没听说过。\n");
	if (SCBORN_D->query_scborn_times(me)!=SCBORN_D->query_scborn_times(obj))
		return notify_fail("红娘笑道：你们不是一个辈分的人，没法成亲。\n");
	if( userp(obj) && !((object)obj->query_temp("marks/"+me->name(1))))
	{
		message_vision(MAG "\n$N对著$n说道："+ RANK_D->query_self(me)
			+ me->name() + "，愿意和"+ RANK_D->query_respect(obj)
			+ "结为夫妇\n\n"NOR, me,obj);
		me->set_temp("marks/"+obj->name(1), 1);
		tell_object(obj, MAG "如果你愿意和对方结为夫妇，请你也对"
			+me->name() + "("+(string)me->query("id")+
			")"+ "下一次 marry 指令。\n" NOR);
		write(MAG "现在你急切盼望着你的心上人说同意……\n" NOR);
		return 1;
	}

	me->add("couple/times",1);
	me->set("couple/have_couple",1);
	me->set("couple/couple_id", obj->query("id"));
	me->set("couple/couple_name", obj->query("name"));
	obj->add("couple/times",1);
	obj->set("couple/have_couple",1);
	obj->set("couple/couple_id", me->query("id"));
	obj->set("couple/couple_name", me->query("name"));
	if (me->query("gender")=="男性")
	{
		obj->set("couple/couple_gender", "丈夫");
		me->set("couple/couple_gender", "妻子");
	}
	else
	{
		me->set("couple/couple_gender", "丈夫");
		obj->set("couple/couple_gender", "妻子");
	}

	message_vision(MAG"恭喜 $N 和 $n ，一对璧人终于喜结良缘。\n"NOR,obj,me);
	CHANNEL_D->do_channel(this_object(), "chat",
		sprintf("%s 和 %s 现在开始是夫妇啦！\n",me->name(1),obj->name(1)));
	return 1;
}

int do_unmarry(string arg)
{
	object me = this_player();
	object ob, couple_ob;
	int i, have_marry;
	string target, tmpstr1, tmpstr2,str1,str2;
	string cardname;

	if( !environment() || base_name(environment()) != query("startroom") )
		return notify_fail("红娘笑道: 真是抱歉，请您等一下到红娘庄来找我吧。\n");
	if (!me->query("couple/couple_id"))
		return notify_fail("红娘笑道: 你没有伴侣。\n");
	if (!objectp(couple_ob=present(arg,environment(me)))||!find_player(arg))
		return notify_fail("红娘笑道: 你的伴侣现在不在场。\n");
	if ((string)couple_ob->query("gender") != "女性")
	{
		tmpstr1 = "老婆"; tmpstr2 = "老公";
		str1 = "她"; str2 = "他";
	} else
	{
		tmpstr1 = "老公"; tmpstr2 = "老婆";
		str1 = "他"; str2 = "她";
	}
	if (me->query("couple/couple_id") != couple_ob->query("id") ||
		couple_ob->query("couple/couple_id") != me->query("id") )
		return notify_fail("红娘笑道: "+str2+"不是你的"+tmpstr2+"，你这是离的什么婚啊。\n");

	if( userp(couple_ob) && !((object)couple_ob->query_temp("marks/"
		+ "unmarry" +me->name(1))) )
	{
		message_vision(MAG "\n$N对著$n说道：" + RANK_D->query_self(me)
			+ me->name() + "，咱们解除婚约吧！好吗？\n\n"
			NOR, me, couple_ob);
		me->set_temp("marks/"+"unmarry"+couple_ob->name(1), 1);
		tell_object(couple_ob, MAG "如果你愿意解除婚约，请你也"
			+ "下一次 unmarry 指令。\n" NOR);
		write(MAG "现在你只有等着" +str2 +" 同意啦...\n" NOR);
		return 1;
	}
	me->delete("couple/have_couple");
	me->delete("couple/couple_id");
	me->delete("couple/couple_name");
	me->delete("couple/couple_gender");
	couple_ob->delete("couple/have_couple");
	couple_ob->delete("couple/couple_id");
	couple_ob->delete("couple/couple_name");
	couple_ob->delete("couple/couple_gender");

	// 记录玩家离婚次数，该属性与学习速度等相关。
	// Added by Constant Jan 11 2001
	if (!me->query("divorce"))
		me->set("divorce", 1);
	else
		me->add("divorce", 1);

	if (!couple_ob->query("divorce"))
		couple_ob->set("divorce", 1);
	else
		couple_ob->add("divorce", 1);

	message_vision(MAG" $N 和 $n 从现在开始解除婚约!\n"NOR,couple_ob, me);
	CHANNEL_D->do_channel(this_object(), "chat",
	sprintf( "聚散皆是缘，%s 和 %s 从今以后，劳燕分飞，互不相干! \n",
	me->name(1), couple_ob->name(1)));

	return 1;
}

