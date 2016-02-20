// mei.c
inherit NPC;
#include <ansi.h>
void create()
{
        set_name( "梅超风" ,({ "mei chaofeng", "mei" }));
        set("title", "黑风双煞");
        set("nickname", HIB"铁尸"NOR);
        set("gender", "女性");
        set("age", 32);
        set("long",
            "梅超风是黄药师唯一的女弟子，本来极受黄药师疼爱，可惜她与师兄陈玄风\n"
            "暗生情愫，他们偷了《九阴真经下卷》私奔。\n"
            "她面色大概因为久居海岛显得黝黑，模样却颇为俏丽。她在桃花弟子中尤精\n"
            "通鞭法。\n");
        set("attitude", "aggressive");
        set("str", 27);
        set("int", 32);
        set("con", 35);
        set("max_qi",2500);
        set("max_jing",1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 1000000);

        set_skill("claw", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("dodge", 40);
        set_skill("jiuyin-baiguzhao", 90);
        set_skill("bibo-shengong", 90);
        set_skill("anying-fuxiang", 90);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("claw", "jiuyin-baiguzhao");

        create_family("桃花岛", 2, "被逐弟子");
        set("inquiry", ([
           "铁尸":     "江湖上的人都这么叫我的，你怕不怕？哈哈哈哈。",
           "东邪":     "那是我师父的绰号。",
           "西毒":     "那是与家师齐名的高手之一，是个老毒物，住在白驼山。",
           "南帝":     "段王爷已出家当和尚去了，法名叫一灯。",
           "北丐":     "北丐统领中原的丐帮，势力颇为强大。",
           "洪七公":   "洪七公武功高强，而且教会郭靖那小儿降龙十八掌，可恨！",
           "黄蓉":     "她是我师父的独女，最是刁蛮任性。",
           "郭靖":     "哼，就是这个小子暗算了我师哥，我绝不会放过他！",
           "杨康":     "康儿是我的徒弟，你见过他么？",
           "梅超风":   "不就是我么？你是白痴啊？",
           "陈玄风":   "他是我的师哥，也是我的夫君，可惜被郭靖那小儿暗算了。",
           "黄药师":   "他是我师父。"]) );
        setup();
        carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}

