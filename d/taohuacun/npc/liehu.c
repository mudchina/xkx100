
inherit __DIR__"changer.c";

void  create()
{
	set_name("ÁÔ»§", ({ "lie hu" }));
	set("gender", "ÄÐÐÔ");
	set("age", 25);
	set("per", 15);
	set("combat_exp", 1000);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/zhangrou",
        	__DIR__"obj/turou",
        	__DIR__"obj/banjiu",
        }));	
        set("want_goods", ({
        	__DIR__"obj/egg",
        	__DIR__"obj/lizi",
        }));	
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_change", "change");
	add_action("do_list", "list");
}

