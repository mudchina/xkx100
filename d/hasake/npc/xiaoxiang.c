#include <ansi.h>

inherit NPC;

void create()
{
        set_name("潇湘子", ({ "xiaoxiang zi", "zi", "xiaoxiang" }));
        set("title", "湘西名宿");
        set("long", "他身材高瘦，脸无血色，形若僵尸。脸上隐隐透著一股青气，手持一根哭丧棒。\n");
        set("gender", "男性");
        set("rank_info/respect", "道长");
        create_family("丐帮", 15, "弟子");
        set("age", 43);
        set("attitude","heroism");
        set("str", 26);
        set("dex", 20);
        set("con", 23);
        set("int", 22);
        set("shen", -7000);
        set("env/wimpy", 60);
        set_skill("parry", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("staff", 100);
        set_skill("huntian-qigong", 120);       
        set_skill("tianshan-zhang", 120);  
        set_skill("xiaoyaoyou", 120);
        set_skill("suohou-hand", 120);
        set_skill("hand", 100);
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("hand", "suohou-hand");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("hand", "suohou-hand");
        set("combat_exp", 700000);
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("eff_jingli", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("inquiry", ([            
            "金轮法王" : "嘿嘿，我迟早会把那个老和尚的国师名号抢过来。",
            "马光佐" : "那是个莽夫，提他做什？",
            "尹克西" : "这人功夫不错，就是满身的金银太耀眼，不象个武林人士。",
            "尼摩星" : "西域来的，内功不错。就是，嘿嘿，心眼太小。",            
       ]) );
        setup();
        set("chat_chance", 45);
        set("chat_msg", ({
            "潇湘子眼睛向你斜望，嘴角边微微冷笑。\n",
            (: random_move :),  
            "潇湘子道：「西藏武功传自天竺，难道世上当真有青出於蓝之事麽？兄弟可有点不大相信了 。」\n", 
            (: random_move :),          
        }) );
        carry_object(WEAPON_DIR"gangzhang")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();
}

void kill_ob(object me)
{     object ob=this_object();
      command("grin");
      command("say 杖下领死吧！");
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));            
      ::kill_ob(me);
}
