// chi.c
// Last Modified by winder on Aug. 25 2001

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("迟百城", ({ "chi baicheng", "baicheng", "chi" }) );
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 25);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2000);
        set("max_neili", 2000);
        set("max_qi",3000);
        set("max_jing",800);
        set("combat_exp", 500000);
        set("shen_type", 1);
	set("ts_xl", 1);
        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set_skill("strike", 100);
	set_skill("kuaihuo-strike",100);
        set_skill("sword", 100);
	set_skill("taishan-sword",100);
        set_skill("force", 100);
	set_skill("panshi-shengong",100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
	set_skill("fengshenjue",100);

        map_skill("sword", "taishan-sword");
        map_skill("parry", "taishan-sword");
        map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike","kuaihuo-strike");

        create_family("泰山派", 14, "弟子");
        setup();

	carry_object(WEAPON_DIR+"sword/houjian")->wield();
	carry_object(CLOTH_DIR+"daopao")->wear();
}

void init()
{
        object ob;

        ::init();

        if( interactive(ob=this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{
        string family;
	object *inv;
	int i;

	inv=all_inventory(environment(this_object()));
	if(! inv) return;
	for(i=0;i<sizeof(inv);i++)
	{
		if(!userp(inv[i])) continue;
		family=(string)inv[i]->query("family/family_name");
		if(family=="泰山派") continue;
		if(inv[i]->is_fighting())
		{
			command("say "+inv[i]->query("name")+"，你竟敢在泰山上撒野，我看你是不想活了！");
			kill_ob(inv[i]);
			inv[i]->fight_ob(this_object());
		}
	}
}
