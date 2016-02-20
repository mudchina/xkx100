// Jay 3/17/96
inherit NPC;
string ask_li();
void create()
{
        set_name("计老人", ({ "ji laoren", "ji"}));
        set("gender", "男性");
        set("age", 83);
        set("long", "满头白发，竟无一根是黑的，身材甚是高大，
只是弓腰曲背，脸上全是皱纹，衰老已极。\n");
        set("attitude", "friendly");
        set("combat_exp", 475000);
        set("shen", 4800);
        set("str", 22);
        set("int", 22);
        set("con", 22);
        set("dex", 24);
        set("max_qi", 800);
        set("max_jing", 500);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 10);
        set_skill("changquan", 90);
        set_skill("liuhe-blade", 90);
        set_skill("cuff", 90);
        set_skill("xiaoyaoyou", 90);
        set_skill("force", 90);
        set_skill("huntian-qigong", 90);
        set_skill("blade", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        map_skill("force", "huntian-qigong");
        map_skill("blade", "liuhe-blade");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "liuhe-blade");
        map_skill("cuff", "changquan");
        prepare_skill("cuff", "changquan");
        set("inquiry", ([
            "李文秀" : (: ask_li :),
            "哈萨克人" : "哈萨克人最爱喝又香又烈的美酒。\n",
            "华辉" : "谁？我不知道这个人。\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/bishou")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
      if (clonep(this_object())) 
        carry_object(__DIR__"obj/rousisuo");
}

string ask_li()
{
    object me, ob, where;
    me=this_player();
    ob = find_living("li wenxiu");
    if (!ob) return "这孩子，不知道又跑哪去了，唉。。。\n";
    where = environment(ob);
       if (!where) return "这孩子，不知道又跑哪去了，唉。。。\n";
    return "哦，这孩子好象跑到"+where->query("short")+"玩去了。";        
}
