// yinggu.c 刘瑛姑

#include <ansi.h>

inherit NPC;
//inherit F_SKILL;
string ask_book();
string ask_yideng();
void create()
{
        set_name("刘瑛姑", ({ "liu yinggu", "liu", "yinggu" }));
        set("gender", "女性");
        set("nickname", CYN "神算子" NOR ) ;
        set("age", 42);
        set("long",
        "但见她额头满布皱纹，面颊却如凝脂，一张脸以眼为界，上
半老，下半少，却似相差了二十多岁年纪。\n",);

        set("combat_exp", 1000000);
        set("shen_type", 1);
        set("per", 20);
        set("int", 20);
        set("str", 20);
        set("dex", 20);
        set("con", 20);

        set("max_neili", 2000);
        set("neili", 2000);
        set("jiali", 0);

        set_skill("force", 100);
        set_skill("kurong-changong", 100);
        set_skill("sword", 120);
        set_skill("duanjia-sword",120);
        set_skill("dodge", 120);
        set_skill("tiannan-step", 120);      //金雁功
        set_skill("unarmed", 100);
        set_skill("kongming-quan",100);     //空明拳
        set_skill("parry", 120);
        set_skill("literate",80);

        map_skill("force", "kurong-changong");
        map_skill("sword", "duanjia-sword");
        map_skill("dodge", "tiannan-step");
        map_skill("parry", "duanjia-sword");
        map_skill("unarmed","kongming-quan");

        set("inquiry", ([
                "周伯通"     : "他、他、、他在哪里！",
                "段智兴"     : "这个老和尚，枉称慈悲！\n",
                "一灯大师"   : (: ask_yideng :),
                "九章算术"   : (: ask_book :),
        ]) );
	set("book_count", 1);
	set("yideng_count", 1);

        setup();
        carry_object(__DIR__"obj/black_cloth")->wear();
}

string ask_book()
{
	mapping fam; 
	object ob;

	if ( (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "大理段家") ||
		(query("book_count") < 1) ) 
		return RANK_D->query_respect(this_player()) + 
		"说什么？我实在不明白。";

	if (this_player()->query_skill("literate",1) < 100)
		return RANK_D->query_respect(this_player()) + 
		"想要这书？你还读不懂它呢。";
	add("book_count", -1);
	ob = new("/clone/book/lbook4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到九章算术啦。\n");
	return "好吧，这本「九章算术」你拿回去好好钻研。\n";
}

string ask_yideng()
{
	mapping fam; 
	object ob;
	
	if (query("yideng_count") < 1)
		return RANK_D->query_respect(this_player()) + 
		"想说什么？找一灯大师，那可别找我。";
	add("yideng_count", -1);
	ob = new(__DIR__"obj/whiteobj");
	ob->move(this_player());
	ob = new(__DIR__"obj/yellowobj");
	ob->move(this_player());
	ob = new(__DIR__"obj/redobj");
	ob->move(this_player());
	return "你想见他？好吧，这三个囊儿给你，有缘你就去找他吧。\n";
}
