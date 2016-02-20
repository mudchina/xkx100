///xieyan.c 谢烟客

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("谢烟客", ({ "xie yanke", "xie", "yanke" }));
        set("long", "他就是摩天崖的主人。看年纪大约五十多岁，\n"
                   +"年轻时好武成兴，无比骄傲，自认为天下第一。\n");
        set("gender", "男性");
        set("age", 50);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 30);
        set("int", 29);
        set("con", 30);
        set("dex", 28);

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);

        set("combat_exp", 1500000);
        set("score", 200000);
        set_skill("force", 170);
        set_skill("unarmed", 100);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("hand",170);
        set_skill("staff", 170);

        set_skill("hamagong", 200);
        set_skill("chanchu-bufa", 150);
        set_skill("shexing-diaoshou", 100);
        set_skill("lingshe-zhangfa", 150);

        map_skill("force", "hamagong");
        map_skill("dodge", "chanchu-bufa");
        map_skill("unarmed", "shexing-diaoshou");
        map_skill("hand", "shexing-diaoshou");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("staff", "lingshe-zhangfa");


        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        add_money("gold",2);
}

