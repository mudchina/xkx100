
inherit __DIR__"changer.c";

int ask_for_y();

int yingtao = 1;

void  create()
{
	set_name("瓜农", ({ "gua nong" }));
	set("gender", "男性");
	set("age", 25);
	set("per", 15);
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/cuke",
        	__DIR__"obj/carrot",
        	__DIR__"obj/donggua",
        	__DIR__"obj/bean",
        }));	
        set("want_goods", ({
        	__DIR__"obj/chop",
        	__DIR__"obj/hen",
        }));	
        set("inquiry", ([
        	"樱桃"	: (: ask_for_y :),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_change", "change");
	add_action("do_list", "list");
}

int  ask_for_y()
{
	object me = this_player(), ob;
	
	if ( yingtao == 0 || random(me->query("kar")) < 10 ) 
                command( "say 您来得太迟，樱桃我已经送人了。" );
	else {
		command( "say 我自己栽的樱桃树今年结果了，摘了满满一篮那。" );
		command( "say 既然这位" + RANK_D->query_respect(me) + "开口了，就送你一些吧。" );
		message_vision( "瓜农从篮里倒了一些樱桃出来送给$N。\n", me );
		ob = new( __DIR__"obj/yingtao" );
		ob->move( me );
		yingtao = 0;
	}
	return 1;
}
