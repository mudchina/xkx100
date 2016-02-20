
inherit __DIR__"changer.c";

void  create()
{
	set_name("Óã··", ({ "yu fan" }));
	set("gender", "ÄÐÐÔ");
	set("age", 25);
	set("per", 15);
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/xiaren",
        	__DIR__"obj/caoyu",
        	__DIR__"obj/liyu",
        	__DIR__"obj/shanyu",
        	__DIR__"obj/manyu",
        }));	
        set("want_goods", ({
        	__DIR__"obj/xianggu",
        }));	
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_change", "change");
	add_action("do_list", "list");
}

