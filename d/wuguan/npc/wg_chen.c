// wg_chen.c

inherit NPC;
string do_getling();
void create()
{
	set_name("陈有德", ({ "chen youde", "chen" }));
	set("title", "扬州武馆馆主");
	set("gender", "男性");
	set("nickname", "铁掌龙威");	
	set("age", 50);
	set("str", 30);
	set("dex", 26);
	set("long", "这人紫金脸庞，面带威严，威武有力，站在那里就象是一座铁塔。\n他好像最近在为各个门派新人分发推荐令。\n");
	set("combat_exp", 1000000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("qi", 2500);
	set("max_qi", 2500);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);
	set("inquiry",  ([
	    "工作" : "呵呵，你去找张总管吧，他会安排你的。",
	    "练功" : "东西练武场都可以练的，你去那练吧。",
	    "推荐令" 	:(:do_getling:),
//	    		"job" : (: ask_job :),
	    "ling" :	(:do_getling:),
	]));
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("axe", 80);
	set_skill("blade", 80);
	set_skill("claw", 80);
	set_skill("club", 80);
	set_skill("cuff", 80);
	set_skill("dagger", 80);
	set_skill("finger", 80);
	set_skill("hammer", 80);
	set_skill("hand", 80);
	set_skill("hook", 80);
	set_skill("leg", 80);
	set_skill("spear", 80);
	set_skill("staff", 80);
	set_skill("stick", 80);
	set_skill("strike", 80);
	set_skill("sword", 80);
	set_skill("throwing", 80);
	set_skill("unarmed", 80);
	set_skill("whip", 80);
	set_skill("changquan", 40);
	set_skill("sanshou", 40);
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");
	setup();
	carry_object("clone/cloth/cloth")->wear();
}



int accept_object(object who, object ob)
{
    if (who->query("combat_exp")>= 100000)
    {
        message_vision("陈有德望着$N说：你的武功应该历练江湖才能再长进，不能埋没
在这里了。\n", who);
        return 0;
    }
    if (ob->query("money_id") && ob->value() >= 500)
    {
        who->set_temp("marks/yangzhou_paied",1);
        message_vision("陈有德对$N说：好！这位" + RANK_D->query_respect(who) 
+ "想学什么呢？\n" , who);
        return 1;
    }
    else
        message_vision("陈有德皱眉对$N说：钱我不在乎。可你也给的也太少了点儿吧？\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/yangzhou_paied")==1) return 0;
        return 1;
}
string do_getling()
{
	object ob=this_player();
	object me=this_object();
	object obj;
	if (!ob->query("family"))
		return "这位"+RANK_D->query_respect(ob)+"还没选好去哪里学艺吧，留在武馆学一些基本功也好。";
	if (ob->query("combat_exp")<20000)
		return "这位"+RANK_D->query_respect(ob)+"似乎太柔弱了些，还是多修炼一段时日再说。";
	if (ob->query("combat_exp")>800000)
		return "大侠您到我们这里写回忆录来了？";
	if (present("ling", ob))
		return "你身上不是有个令了吗。";
	if (ob->query_temp("getling"))
		return "我刚刚不是才给过你推荐令了。";
	if (ob->query("teachwg/force")>=100 && ob->query("teachwg/dodge")>=100 && ob->query("teachwg/parry")>=100)
		return "我看这推荐令给你也没用，还是算了吧。";
	command("smile");
	command("say 这位"+RANK_D->query_respect(ob)+"来得正好，有很多门派派人在我这里教导新的入门弟子。");
	obj=new(__DIR__"obj/ling");
	obj->move(me);
	ob->set_temp("getling",1);
	command("give ling to "+ob->query("id"));
	return "我这里有块推荐令，你先拿去，一定用得上的。";
}


