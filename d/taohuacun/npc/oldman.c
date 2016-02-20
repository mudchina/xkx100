
inherit __DIR__"changer.c";

int ask_for_s();

int sunjian = 1;

void  create()
{
	set_name("老农", ({ "old man" }));
	set("gender", "男性");
	set("age", 50);
	set("per", 15);
	set("long", "一位山里来的老大爷。\n");
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/xianggu",
        	__DIR__"obj/lizi",
        }));	
        set("inquiry", ([
        	"笋尖"	:  (: ask_for_s :),
        ]));
        set("want_goods", ({
        	__DIR__"obj/cuke",
        	__DIR__"obj/meat",
        }));	
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_change", "change");
	add_action("do_list", "list");
}

int  ask_for_s()
{
	object me = this_player(), ob;
	
	if ( sunjian == 0 || random(me->query("kar")) < 10 ) 
                  command( "say 您来得太迟，笋尖我已经送人了。" );
 	else
 	   {
	          command( "say 我摘香菇的时候顺便摘了些笋尖，这位" + RANK_D->query_respect(me) + "要的话就送给你好了。" );
		  message_vision( "老农送给$N一袋笋尖。\n", me );
		  ob = new( __DIR__"obj/sunjian" );
		  ob->move( me );
		  sunjian = 0;
	   }
	return 1;	
}