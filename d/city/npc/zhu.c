// zhu.c 朱熹

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
#include "exam.h"
#include <localtime.h>
int give_quest(object ob);
int now_time();
string ask_buy();
// int ask_degree();

string * degree_desc = ({
BLU "文盲" NOR, BLU "童生" NOR, BLU "秀才" NOR, CYN "举人" NOR, 
CYN "解元" NOR, CYN "贡士" NOR, CYN "会元" NOR, GRN "进士" NOR, 
GRN "探花" NOR, GRN "榜眼" NOR, GRN "状元" NOR, HIY "翰林院士" NOR, 
HIY "翰林硕士" NOR, HIY "翰林博士" NOR, HIY "翰林院编修" NOR, 
HIR "庶吉士" NOR, HIR "学士" NOR, HIR "内阁大学士" NOR, 
HIR "内阁首辅" NOR, MAG "文学大宗师" NOR, HIW "圣人" NOR,
});
string * rank = ({
BLU"文盲"NOR,     BLU"童生"NOR,     BLU"秀才"NOR,     CYN"举人"NOR,
CYN"解元"NOR,     CYN"贡士"NOR,     CYN"会元"NOR,     GRN"进士"NOR,
GRN"探花"NOR,     GRN"榜眼"NOR,     GRN"状元"NOR,     HIY"翰林院士"NOR,
HIY"翰林硕士"NOR, HIY"翰林博士"NOR, HIY"翰林编修"NOR, HIR"庶吉士"NOR,
HIR"学士"NOR,     HIR"大学士"NOR,   HIR"内阁首辅"NOR, MAG"大宗师"NOR,
HIW"圣人"NOR,
});
int * nlvl = ({
0,10,20,30,40,50,60,70,80,90,100,
120,140,160,180,200,220,240,260,280,300,
});

void create()
{
	set_name("朱熹", ({ "zhu xi", "zhu" }));
	set("long",
"朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。\n");
	set("gender", "男性");
	set("age", 65);
	set("no_get", 1);
	set("gongming/lvl", 20);
	set("gongming/rank","圣人");
	set_skill("literate", 300);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	set("inquiry", ([
//		"学位" : (:ask_degree:),
		"学位" : "十年寒窗，一朝金榜题名。你想在这里考取学位(exam)？",
		"买书" : (:ask_buy:),
		"书"   : "唉！书到用时方恨少。",
		"借书" : "借？你不还我到哪里找你？哼！",
	]));
	set("vendor_goods", ({
		BOOK_DIR"lbook1",
		BOOK_DIR"lbook2",
		BOOK_DIR"lbook3",
	}));
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"朱熹说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		"朱熹说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
		"朱熹说道：大学之道，在明明德。在亲民，在止于至善。 \n",
		"朱熹说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
	}) );
}
int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/朱"))
		return 0;
	ob->add_temp("mark/朱", -1);
	return 1;
}
int accept_object(object who, object ob)
{
	object me = this_player();
	if (!(int)who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/朱", ob->value() / 50);
	if( me->query_skill("literate", 1) > 19){
		tell_object(me,"你现在已有一定的文化知识,也可以自己读书深造了。\n");
		return 1;
		}
	return 1;
	}
}
string ask_buy()
{
	return "我这可有不少读书人必读的书哟！\n";
}

void init()
{
	::init();
	add_action("do_exam","exam");
	add_action("do_answer","answer");
	add_action("do_list","list");
	if(this_player()->query_skill("literate", 1) > 19)
		add_action("do_buy", "buy");
	return;
}
/*
int ask_degree()
{
	int lv;
	object ob = this_player();
	lv = (ob->query_skill("literate") / 5);
	if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1; 
	if (lv < 3) 
	{
		command("say "+ob->query("name")+"，你那点墨水也好意思问？随便给你个学位就算了！\n");
		ob->set("degree",degree_desc[lv]);
		return 1;
	}
	if (lv < 10) 
	{
		command("say "+ob->query("name")+"，呃，不错，有前途，很高兴授予学位给你，继续好好努力！\n");
		ob->set("degree",degree_desc[lv]);
		return 1;
	}
	else
	{
		command("say 果然是长江后浪逐前浪啊，"+ob->query("name")+"，我非常荣幸能有机会为你授学位！\n");
		ob->set("degree",degree_desc[lv]);
		return 1;
	}
}
*/
int do_exam()
{
	object ob = this_player();
	int level;
	string rank;

	if(!ob||environment(ob)!=environment()) return 0;
	level=ob->query("gongming/lvl");

	if(level)
	{
		rank=ob->query("gongming/rank");
		if (level>=query("gongming/lvl"))
			return notify_fail("朱熹惊讶道："+rank+"大人，不要开玩笑了。\n");
	}
	if(ob->query_skill("literate",1)<10 ||
		ob->query_skill("literate",1) < nlvl[level+1])
		return notify_fail("朱熹摇头道：等你多读些书再来吧。\n");
	if(now_time()==ob->query("gongming/last_check"))
		return notify_fail("朱熹瞄了你一眼道：明天再来吧！\n");
	if(ob->query_temp("gongming/answer"))
		return notify_fail("朱熹指着你道：问题还没回答吧！\n");
	give_quest(ob);
	return 1;
}
int give_quest(object ob)
{ 
	mapping quest;
	string *text,word,pass;
	int i;

	quest=exam[random(sizeof(exam))];
	text=quest["text"];
	i=random(sizeof(text));
	if (random(2)==1)
	{
		if (i!=0)
		{
			word=text[i-1];
			pass="前一句";
		}
		else
		{
			word=quest["author"];
			pass="作者";
		}
	}
	else
	{
		if (i!=(sizeof(text)-1))
		{
			word=text[i+1];
			pass="后一句";
		}
		else
		{
			word=quest["title"];
			pass="题目";
		}
	}
	ob->set_temp("gongming/answer", word);
	ob->set_temp("gongming/time", time()); 
	if(!ob->query_temp("gongming/count")) ob->set_temp("gongming/count",1);
	else ob->add_temp("gongming/count", 1);
	command("say "+text[i]+"... ...请问"+pass+"是？请回答(answer)。");
	return 1;
}
int do_answer(string arg)
{
	object ob=this_player();
	int lvl;

	lvl = ob->query("gongming/lvl");
	if (!ob->query_temp("gongming/answer"))
		return notify_fail("朱熹笑道：我可还没出题，你胡说些什么？\n");
	if (!arg)
		return notify_fail("朱熹笑道：想好了再回答，别急。\n");
	message_vision(HIC"$N应声答道："+arg+"！\n"NOR, ob);
	if (arg==ob->query_temp("gongming/answer") || wizardp(ob))
	{
		command("nod");
		ob->delete_temp("gongming/answer");
		if (ob->query_temp("gongming/count") < lvl)
		{
//			give_quest(ob);
			remove_call_out("give_quest");
			call_out("give_quest", 2, ob);
			return 1;
		}
		else
		{
			lvl++;
			if(lvl < 10)
				message("channel:chat",HIR"【喜报】朱熹：“恭贺"+ob->query("name")+"高中"+rank[lvl]+HIR"！京师连登黄甲！”\n"NOR, users());
			else
				message("channel:chat",HIY"【喜报】朱熹：“恭贺"+ob->query("name")+"荣升"+rank[lvl]+HIY"！！”\n"NOR, users());
			ob->set("gongming/rank",rank[lvl]);
			ob->set("gongming/lvl", lvl);
			ob->set("degree", rank[lvl]);
			ob->delete_temp("gongming");
			return 1;
		}
	}
	command("shake");
	command("say 不要灰心，明天再来。");
	ob->delete_temp("gongming/answer");
	if(!wizardp(ob)) ob->set("gongming/last_check", now_time());
	return 1;
}
int now_time()
{
	int i;
	object ob=this_player();
	mixed *local;

	local = localtime(time()*60);
	i=local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0);
	return i;
}

