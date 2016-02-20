// yue-lingshan.c

inherit NPC;

void create()
{
	object ob;
        set_name("岳灵珊", ({ "yue lingshan", "yue", "lingshan" }) );
        set("nickname", "小师妹");
        set("gender", "女性" );
        set("age", 17);
        set("per", 29);
        set("str", 16);
        set("con", 24);
        set("dex", 30);
        set("int", 27);

        set("attitude", "friendly");

        set("max_qi",800);
        set("max_jing",500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 80);
        set("combat_exp", 100000);

        set("long",     "岳灵珊是华山派掌门岳不群的独生女儿。\n");

        create_family("华山派", 14, "弟子");

        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("force", 60);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("literate", 70);

        set_skill("huashan-sword", 50);
        set_skill("yunu-sword", 80);
        set_skill("chongling-sword", 120);
        set_skill("huashan-ken", 50);
        set_skill("feiyan-huixiang", 50);

        map_skill("sword", "yunu-sword");
        map_skill("parry", "yunu-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        setup();
        if (clonep())
        {
        	ob=new(WEAPON_DIR"treasure/greenwater-sword");
        	if ( ob->violate_unique())
        	{
        		destruct(ob);
        		ob=new(WEAPON_DIR"changjian");
       		}
          ob->move(this_object());
          ob->wield();
       	}
        carry_object("/clone/cloth/cloth")->wear();

}

int accept_fight(object me)
{
        command("say 小女子怎会是你的对手?");
        return 0;
}
