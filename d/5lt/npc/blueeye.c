// blueeye.c
inherit NPC;
inherit F_DEALER;

#include <ansi.h>


void create()
{
	set_name("叮当妹", ({ "blueeye" }));
	set("title", "甜品店老板");
	set("shen_type", 1);

	set("gender", "女性" );
	set("long", "叮当妹正笑呵呵地看着你，“西西！不要这样看人家嘛。好羞涩哦！”\n");
	set("nickname", HIW"冰雪聪明活泼可爱"NOR);
	set("age", 20);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");
	set("vendor_goods",({
		__DIR__"obj/bing",
		__DIR__"obj/bing2",
	}));        

	set("inquiry", ([
                 "yoyo": "哥哥一直都在电视台啊，电视台就在无厘头村的西北边。\n",
	]));                 
	set("combat_exp", 100000);

	setup();

	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}