// Room: /d/xingxiu/yin.c
// Last Modified by winder on Apr. 25 2001
#include <ansi.h>
inherit NPC;

void create()
{
	object ob;
	set_name("尹克西", ({ "yin kexi", "yin", "kexi" }));
	set("title", "西域大贾");
	set("long", 
"他高鼻深目，曲发黄须，是个胡人，颈悬明珠腕带玉镯，
珠光宝器。是波斯大贾，世代贩卖珠宝。\n");
	set("gender", "男性");       
	set("age", 43);
	set("attitude","peaceful");
	set("str", 32);
	set("dex", 24);
	set("con", 26);
	set("int", 25);
	set("shen", -7000);
	set("env/wimpy", 60);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 120);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 100);
        set_skill("unarmed", 100);
        set_skill("yujiamu-quan", 80);
        set_skill("parry", 100);
        set_skill("sword", 70);
        set_skill("mingwang-jian", 60);
        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
	set("combat_exp", 750000);
	set("max_qi", 2200);
	set("max_jing", 2000);
	set("eff_jingli", 1500);
	set("jiali", 50);
	set("inquiry", ([	    
	    "金轮法王" : "嘿嘿，我迟早会把那个老和尚的国师名号抢过来。", 
	]));

	set("chat_chance", 30);
	set("chat_msg", ({
	    "尹克西眼睛向你斜望，嘴角边微微冷笑。\n",
	    (: random_move :),
	}));
	setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        ob = new("clone/weapon/treasure/jinlongbian");
        if (ob->violate_unique()) destruct(ob);
        else ob->move(this_object());
}

void kill_ob(object me)
{     object ob=this_object();
      command("hehe");
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);	 
      ::kill_ob(me);
}
