#include <ansi.h>
inherit NPC;
void create()
{
       set_name("神秘镖师", ({ "shenmi biaoshi", "biaoshi" }) );
       set("title", "中原镖师");
       set("gender", "男性" );
       set("age", 45);
       set("str", 20);
       set("con", 20);
       set("int", 20);
       set("dex", 20);
       set("env/wimpy", 60);
       set("long", "他是个来自中原的镖师，但他十年来从没回去过，好象是在找什么东西。\n" );
       set("combat_exp", 25000 + random(3000));
       set("shen", -300); 
       set("attitude", "heroism");
       set("chat_chance", 30);
       set("chat_msg", ({
            "神秘镖师好象在自言自语：在哪呢？在哪呢？ \n",
           (: random_move :)
       }) );          
       set("max_qi", 400);
       set("max_jing", 400);
       set("neili", 500);
       set("max_neili", 500);
       set_skill("force", 30); 
       set_skill("unarmed", 30);
       set_skill("sword", 30);
       set_skill("dodge", 30);
       set_skill("parry", 30);       
       setup();       
       carry_object(WEAPON_DIR"changjian")->wield();
       carry_object(CLOTH_DIR"cloth")->wear();
       add_money("silver", 5);
}