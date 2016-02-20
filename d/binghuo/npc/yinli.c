// yinli.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
        set_name("殷离", ({ "yin li", "yin", "li"}));
        set("long",
            "她是张无忌的表妹，殷野王的女儿，一张秀丽的脸蛋因为练千蛛万毒
手的武功，变得浮肿不堪。\n");
        set("gender", "女性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 12);
        set("str", 15);
        set("int", 25);
        set("con", 25);
        set("dex", 30);

        set("max_qi", 500);
        set("max_jing", 200);
        set("max_neili", 500);
        set("jiali", 50);
        set("combat_exp", 50000+random(10000));
        set("score", 20000);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("unarmed", 80);
        set_skill("qianzhu-wandushou", 70);
        set_skill("qingfu-shenfa",50);
        map_skill("dodge", "qingfu-shenfa");
        map_skill("parry", "qianzhu-wandushou");
        map_skill("unarmed", "qianzhu-wandushou");

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 15);
        set("inquiry", ([
            "张无忌" :  "你是问阿牛哥吗？",
            "阿牛"   :  "这个狠心短命的......",
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}
