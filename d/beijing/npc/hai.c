// hai.c 海公公
#include <ansi.h>
inherit NPC;
string ask_for_zigong();
string ask_for_jingong();
int do_pretend ( string arg );

void create()
{
	set_name("海公公", ({"hai gonggong", "hai", "gonggong"}));
	set("title", "东厂千户");
	set("long",
		"他是东厂大太监海大富，乔装改扮成商人模样出京寻欢作乐，长得既像老头又像老太太。\n"
	);

	set("gender", "无性");
	set("rank_info/respect", "公公");

	set("attitude", "heroism");
	set("class", "eunach");

	set("inquiry",([
		"自宫"  : (: ask_for_zigong :),
		"进宫"  : (: ask_for_jingong :),
		"皇宫"  : (: ask_for_jingong :),
	]));

	set("age", 60);
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 75000);
	set("score", 5000);
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("bixie-jian", 50);

	map_skill("dodge", "bixie-jian");
	map_skill("sword", "bixie-jian");
	map_skill("parry", "bixie-jian");

	setup();
	set("chat_chance", 15);

	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/city/obj/jiudai");
	carry_object("/d/beijing/obj/yaofen");
	add_money("silver", 50);
}

void init()
{
	add_action("do_decide", "decide");
	add_action("do_pretend", "pretend");
}


string ask_for_zigong()
{
	object me;

	me = this_player();

	if( (string)me->query("gender")=="无性" )
		return "你我同是阉人，何必开如此无聊的玩笑？\n";

	if( (string)me->query("gender") == "女性" )
		return "我虽已废，但一样可以给你这个小美人带来快乐，要不要试试？\n";
	if ((int)me->query_str() > 28 )
		return "这位好汉过于粗壮，自宫有碍观瞻，不妥，不妥。\n";

	me->set_temp("pending/zigong", 1);
	return "自宫？这位公子相貌堂堂，何必... 我真希望能有你的那个。自宫之后，不可后悔，你若决心已定(decide)，告诉我。\n";
}

string ask_for_jingong()
{
	object me;

	me = this_player();

	if( (string)me->query("gender")=="无性" )
	return("海公公笑吟吟地说道：您既已是公公了，自然可以进宫。\n");          

	if( (string)me->query("gender") == "男性" )
	{
	me->set_temp("pending/zigong", 1);
	return("海公公笑吟吟地说道：并不是一定要自宫才可以进皇宫的；\n"+"不过，你若决心已定(decide)，我就成全了你。\n");
	}

	if( (string)me->query("gender")=="女性" )
	return("海公公摇头道：不行的，你长得太丑了。\n");                
}


int do_decide()
{
	if( !this_player()->query_temp("pending/zigong") )
		return 0;

	message_vision(
		"$N一咬牙，褪下中衣。（女玩家闭眼！）\n\n"
		"$n伸出长剑插到$N两腿之间，飞速一剜，……\n\n"
		"$N顿时惨叫一声昏了过去……\n\n",
		this_player(), this_object() );
	command("chat 嗨……");
	command("hehe");
	this_player()->delete_temp("pending/zigong");
	this_player()->delete_temp("pending/jingong");
	this_player()->set("gender","无性");
	this_player()->set("class", "eunach");
	this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
	this_player()->unconcious();
	
	return 1;
}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if ( (string)ob->query("name") == "药粉") 
	{
	 write(HIC "海公公打开药包，伸出小指，用指甲挑了一点粉末，\n"
	 +"就着酒泯了，仍是不住咳嗽。\n" NOR);
	       if(objectp(present("xiao", environment(me))))
		{
		command("say 奇怪，你怎么也有这种药。");   
		}
	       else
		{
		 command("smile "+ob->query("id"));
		 if(me->query_temp("haspretend"))
		 { 
		 command("say 多谢啦，小桂子，我现在好多了 !");
		 me->delete_temp("haspretend");
		 me->set("huanggong\\canenter", 1);
		 }              
		 else command("say 奇怪，你怎么也有这种药。");   
		}
	}
	else 
	{
		 command("shake ");
		 command("say 这种东西鬼才要 ! 老子宰了你 !");
		 remove_call_out("kill_ob");
		 call_out("kill_ob", 1, this_player());
	}   
	     return 1;
}


int do_pretend ( string arg )
{
   object ob ;
   ob = this_player () ;
   if( !arg && arg!="guizi"&&arg!="xiao"&&arg!="xiao guizi")
     return notify_fail("\n你要装成谁？\n");
   
if(objectp(present("xiao", environment(ob))))
{
write(HIR "\n海公公大叫一声：你敢冒充小桂子，老子宰了你！\n" NOR);
remove_call_out("kill_ob");
call_out("kill_ob", 1, this_player());
return 1;
}
if ( (string) ob -> query ("gender") == "男性")
{
ob->set_temp("haspretend",1);
message_vision("\n$N装成了小桂子，$n没吭声。\n",this_player(),this_object());
message_vision("\n海公公看了$N一眼，说“唉，是不是又该吃药了？”\n",this_player());
return 1;
}
}


void die()
{
	say("海公公挣扎着叹道：唉，老皇爷的事儿我没办成啊！\n");                 
	message_vision("$N惨嚎一声，死了！\n", this_object());
	::die();
}

