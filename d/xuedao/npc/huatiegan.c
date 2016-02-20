// huatiegan.c

inherit NPC;
#include <ansi.h>
void create()
{
       set_name("花铁干", ({ "Hua tiegan", "hua" }));
       set("long", 
       "他就是南四奇“落花流水”中的老二。\n"
       "南四奇横行江南，行侠仗义，花铁干一手中平枪，号称中平无敌。可是他的为人却不咋的。\n");
       set("gender", "男性");
       set("title", "南四奇");
       set("nickname", HIR"中平无敌"NOR);
       set("age", 45);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);

       set("max_qi", 2000);
       set("max_jing", 500);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 30);
       set("combat_exp", 700000);
       set("shen_type", 0);

       set_skill("force", 100);
       set_skill("huashan-neigong", 100);
       set_skill("dodge", 100);
       set_skill("lingxu-bu", 100);
       set_skill("unarmed", 100);
       set_skill("huashan-ken", 100);
       set_skill("parry", 100);
       set_skill("spear", 100);
       set_skill("zhongping-qiang", 100);
       set_skill("literate", 40);

       map_skill("force", "huashan-neigong");
       map_skill("dodge", "lingxu-bu");
       map_skill("unarmed", "huashan-ken");
       map_skill("spear", "zhongping-qiang");
       map_skill("parry", "zhongping-qiang");
       set("chat_chance", 20);
       set("chat_msg", ({
              "花铁干缓缓提起中气，啸声如潮涌出：“落花～～流水……”震人耳馈。\n",
       }));

       setup();
       carry_object("/clone/weapon/changqiang")->wield();
}

