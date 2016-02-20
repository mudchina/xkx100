// sun.c 孙婆婆

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("孙婆婆", ({"sun popo", "sun"}));
        set("gender", "女性");
        set("age", 55);
        set("long",
                "这是一位慈祥的老婆婆，正看着你微微一笑。\n"
        );
        set("attitude", "friendly");

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 40);

        set("combat_exp", 150000);
        set("score", 0);

        set_skill("force", 80);
        set_skill("yunv-xinfa", 60);    //玉女心法
        set_skill("sword", 90);
        set_skill("yunv-jian", 80);     //玉女剑
        set_skill("dodge", 70);
        set_skill("yunv-shenfa", 70);   //玉女身法
        set_skill("parry", 60);
        set_skill("unarmed",80);
        set_skill("meinv-quan", 60);    //美女拳法
        set_skill("literate",40);

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");

        set("inquiry", ([
                "小龙女" : "龙姑娘是我一手带大的，她从小没了父母，现在又独个儿住在这古墓里，唉..\n",
        ]) );

        set("env/wimpy", 50);
        setup();

        carry_object(WEAPON_DIR"changjian")->wield();
        carry_object(CLOTH_DIR"cloth")->wear();

}

