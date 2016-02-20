
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("黄蓉", ({"huang rong", "huang", "rong"}));
    set("title", "桃花岛主独生爱女");
    set("gender", "女性");
    set("age", 18);
	set("long", 
        "这是桃花岛主的独生女儿。由于岛主夫人早死，岛主对这个女儿备加疼爱。\n"
        "她生性跳脱飞扬，喜欢四处乱跑。\n");

	set("attitude", "peaceful");
	
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 500);
    set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
    set("neili", 800);
    set("max_neili", 800);
    set("jiali", 0);
    set("env/wimpy", 60);
	
    set("combat_exp", 150000);
    set("score", 0);
	
    set_skill("force", 60);
    set_skill("bibo-shengong", 80);
    set_skill("unarmed", 80);
    set_skill("luoying-zhang", 80);
       set_skill("dodge", 100);
    set_skill("anying-fuxiang", 80);
    set_skill("parry", 85);
    set_skill("sword", 80);
    set_skill("luoying-shenjian",80);
	
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
	
    create_family("桃花岛", 2, "弟子");
	setup();
    carry_object(__DIR__"obj/ruanwei")->wear();
    carry_object(__DIR__"obj/shudai")->wear();

}

init()
{
    object ob;
	mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
		myfam = (mapping)ob->query("family");
        if ((!myfam || myfam["family_name"] != "桃花岛") &&
			(!wizardp(ob))) {
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
        }
}

void saying(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    if ((string)ob->query("gender") == "男性")
        message_vision("\n黄蓉面现惊奇之色，打量了$N一眼，说到：“你是什么人，"
        "竟敢乱闯我的闺房？\n再不滚出去，看我怎么整你！”\n", ob);
    else
        message_vision("\n黄蓉看了看$N，说到：“好久每生人来过了，"
        "不知这位姐姐可有我靖哥哥的消息？\n", ob);
}

void attempt_apprentice(object ob)
{
    command("say 我年纪这么小就收徒弟，岂不让人笑掉大牙！");
}
