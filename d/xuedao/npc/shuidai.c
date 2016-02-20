// shuidai.c

inherit NPC;
#include <ansi.h>
void create()
{
       set_name("水岱", ({ "shui dai", "shui" }));
       set("long", 
       "他就是南四奇“落花流水”中的老四。\n"
       "南四奇横行江南，行侠仗义，水岱虽富甲东南，现在却深有忧色。\n");
       set("gender", "男性");
       set("title", "南四奇");
       set("nickname", HIC"冷月剑"NOR);
       set("age", 39);
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
       set_skill("huashan-neigong", 100);
       set_skill("dodge", 100);
       set_skill("huashan-shenfa", 100);
       set_skill("strike", 100);
       set_skill("huashan-zhangfa", 100);
       set_skill("parry", 100);
       set_skill("sword", 100);
       set_skill("huashan-jianfa", 100);
       set_skill("literate", 80);

       map_skill("force", "huashan-neigong");
       map_skill("dodge", "huashan-shenfa");
       map_skill("strike", "huashan-zhangfa");
       map_skill("parry", "huashan-jianfa");
       map_skill("sword", "huashan-jianfa");
       set("chat_chance", 20);
       set("chat_msg", ({
              "水岱急提中气，啸声如虹：“落花流水～～……”声势劲急，远远传开。\n",
	}));

       setup();
       carry_object("/clone/weapon/changjian")->wield();
}

