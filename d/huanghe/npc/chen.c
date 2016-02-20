// chen.c
inherit NPC;
#include <ansi.h>
void create()
{
        set_name( "陈玄风" ,({ "chen xuanfeng", "chen" }));
        set("title", "黑风双煞");
        set("nickname", HIY"铜尸"NOR);
        set("gender", "男性");
        set("age", 35);
        set("long",
            "此人是黄药师的二弟子，他浓眉大眼，背厚膀宽，躯体甚是壮健，只是\n"
            "面色微微泛黄。\n");
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
           "铜尸":     "江湖上的人都这么叫我的，你怕不怕？哈哈哈哈。",
           "东邪":     "那是我师父的绰号。",
           "西毒":     "那是与家师齐名的高手之一，是个老毒物，住在白驼山。",
           "南帝":     "段王爷已出家当和尚去了，法名叫一灯。",
           "北丐":     "北丐统领中原的丐帮，势力颇为强大。",
           "洪七公":   "洪七公武功高强，而且教会郭靖那小儿降龙十八掌，可恨！",
           "黄蓉":     "她是我师父的独女，最是刁蛮任性。",
           "梅超风":   "她是我的师妹，也是我的内室。",
           "陈玄风":   "不就是我么？你是白痴啊？",
           "黄药师":   "他是我师父。"]) );
        setup();
        carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}

