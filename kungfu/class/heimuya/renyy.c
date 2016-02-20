// renyy.c
#include <ansi.h>
inherit NPC;
string ask_ling();
int ask_tuijiao();

void create()
{
	set_name("任盈盈", ({ "ren yingying","ren","ying"}) );
	set("gender", "女性" );
	set("long", "她睫毛甚长，容貌丽都，秀丽绝伦，不过十七八岁年纪。");
	set("age", 18);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("env/wimpy", 40);
	set("per", 30);
	set("str", 16);
	set("dex", 27);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	
	set("max_qi", 3000);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 200);
	set("combat_exp", 1200000);

	set_skill("luteplaying", 200);      // 绕梁琴艺
	set_skill("literate", 100);         // 读书识字
	set_skill("force", 180);            // 基本内功
	set_skill("dodge", 180);            // 基本躲闪
	set_skill("unarmed", 180);          // 基本拳脚
	set_skill("parry", 180);            // 基本招架
	set_skill("dagger", 180);           // 基本刺法
        set_skill("shigu-bifa", 180);       // 石鼓打穴笔法
	set_skill("piaoyibu", 180);         // 飘逸步法
	set_skill("kuihua-xinfa", 180);     // 葵花心法
	set_skill("xixing-dafa", 50);       // 吸星大法
	set_skill("changquan", 180);        // 太祖长拳

	map_skill("force", "xixing-dafa");
	map_skill("dagger", "shigu-bifa");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "shigu-bifa");

	set("chat_chance",60);
    	set("chat_msg",({
	"任盈盈说道：你若能把这封信捎给他，可太谢谢你了.............\n",
	"任盈盈缓缓说道：“咱们武林中人，只怕是注定要不得好死的了。他日后倘若对我负心，我也不盼望他天打雷劈，我……我……我宁可亲手一剑刺死了他。”\n",
	"任盈盈说道：也不知蓝凤凰见没见到他，可真急死我了......\n",
	}) );
       
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", MAG"圣姑"NOR);
	create_family("黑木崖", 8, "弟子");
	set("inquiry",([
		"令狐冲"  : (: ask_ling :),
		"退教"    : (: ask_tuijiao :),
		"tuijiao" : (: ask_tuijiao :),
	]) );
	set_temp("letter",1);
	setup();
	carry_object(CLOTH_DIR"female-cloth")->wear();
	carry_object(CLOTH_DIR"female-shoe")->wear();
	carry_object(WEAPON_DIR"dagger")->wield();
	carry_object("/d/heimuya/npc/obj/letter");
}

string ask_ling()
{
	object me=this_player();
	object obn;

	message_vision("任盈盈说道：去年上华山一去就再无音信，他不会忘记我吧......\n", me );
	if(query_temp("letter")==0)
	{
		message_vision("任盈盈又说道：这位"+ RANK_D->query_respect(me)+"，我已经派蓝凤凰去寻找了，也不知道怎么样了。\n",me);
		return "";
	}
	message_vision("任盈盈又说道：这位"+ RANK_D->query_respect(me)+"，我这里有信，你要是找到令狐冲，就把信交给他，他会明白的。\n" , me);
	obn=new("/d/heimuya/npc/obj/letter");
	obn->move(me);
	set_temp("letter",0);
   
	return ("这封信烦你交给令狐冲。\n");
}
int ask_tuijiao()
{
        object ob;
        ob=this_player();

        if(ob->query("party/party_name") != HIB"日月神教"NOR)
        {
		message_vision("盈盈浅浅一笑，对$N说道：你还没加入我神教呢，就想退教？\n",ob);
		return 1;
        }
        if(ob->query("family/family_name") == "黑木崖" )
        {
	message_vision("盈盈抬起俏脸对$N说道：你已经是黑木崖弟子，如何能退教？\n", ob);
                return 1;
        }

        command("look "+ob->query("id"));
        command("sigh ");
        command("nod ");
        ob->delete("party");
        return 1;
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂长老入教去！\n");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa", 1) < 60)
	{
		command("say 想学我教功夫，在内功上，" + RANK_D->query_respect(ob) + "是否还应该多下点功夫？");
		return;
	}
	command("say 好吧，本姑娘就收下你了。");
	command("recruit " + ob->query("id"));
}

