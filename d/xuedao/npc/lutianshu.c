// lutianshu.c

inherit NPC;
#include <ansi.h>
void create()
{
       set_name("陆天抒", ({ "Lu tianshu", "lu" }));
       set("long", 
       "他就是南四奇“落花流水”中的老大。\n"
       "南四奇横行江南，行侠仗义，陆天抒更是仗义疏财，大有侠名。\n");
       set("gender", "男性");
       set("title", "南四奇");
       set("nickname", HIG"仁义陆大刀"NOR);
       set("age", 51);
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
       set("combat_exp", 800000);
       set("shen_type", 1);

       set_skill("force", 100);
       set_skill("hunyuan-yiqi", 100);
       set_skill("dodge", 100);
       set_skill("shaolin-shenfa", 100);
       set_skill("unarmed", 100);
       set_skill("jingang-quan", 100);
       set_skill("parry", 100);
       set_skill("blade", 100);
       set_skill("wuhu-duanmendao", 100);
       set_skill("literate", 20);

       map_skill("force", "hunyuan-yiqi");
       map_skill("dodge", "shaolin-shenfa");
       map_skill("unarmed", "jingang-quan");
       map_skill("parry", "wuhu-duanmendao");
       map_skill("blade", "wuhu-duanmendao");
       set("chat_chance", 20);
       set("chat_msg", ({
              "陆天抒提起中气，纵声长啸：“落～～花流水……”啸声雄浑，远远群山回应不绝。\n",
	}));

       setup();
       carry_object("/clone/weapon/gangdao")->wield();
}

