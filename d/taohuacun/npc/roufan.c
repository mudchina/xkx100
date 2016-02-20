
inherit __DIR__"changer.c";

int  ask_for_y();
int  ask_for_z();
int  ask_for_n();

int  zuotun = 1;
int  yaozi = 1;
int  erduo = 1;

void  create()
{
	set_name("肉贩", ({ "rou fan" }));
	set("gender", "男性");
	set("age", 25);
	set("per", 15);
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/chop",
        	__DIR__"obj/hen",
        	__DIR__"obj/cock",
        	__DIR__"obj/meat",
        	__DIR__"obj/beef",
        }));	
        set("want_goods", ({
        	__DIR__"obj/baicai",
        	__DIR__"obj/qingcai",
        }));	
        set("inquiry", ([
        	"羊羔坐臀"  :  (: ask_for_y :),
        	"小牛腰子"  :  (: ask_for_n :),
        	"小猪耳朵"  :  (: ask_for_z :),
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
	
	if ( zuotun == 1 && random(me->query("kar")) > 10 ) {
		command( "say 算你走运，我这儿还剩下一块，送给你吧。" );
		message_vision( this_object()->query("name") + "拿出一块羊羔坐臀递给$N。\n", me );
		ob = new( __DIR__"obj/zuotun" );
		ob->move( me );
		zuotun = 0;
	}	
	else 
		command( "say 您来得太迟，羊羔坐臀俺给送人了。" );
	return 1;
}

int  ask_for_n()
{
	object me = this_player(), ob;
	
	if ( yaozi == 1 && random(me->query("kar")) > 10 ) {
		command( "say 这东西可不好弄到，看在老主顾的份上就给你一个吧。" );
		message_vision( this_object()->query("name") + "拿出一个小牛腰子递给$N。\n", me );
		ob = new( __DIR__"obj/yaozi" );
		ob->move( me );
		yaozi = 0;
	}	
	else 
		command( "say 您来得太迟，小牛腰子俺给送人了。" );
	return 1;
}

int  ask_for_z()
{
	object me = this_player(), ob;
	
	if ( erduo == 1 && random(me->query("kar")) > 10 ) {
		command( "say 我留着这玩意儿也没用，你要就拿去。" );
		message_vision( this_object()->query("name") + "拿出一块小猪耳朵递给$N。\n", me );
		ob = new( __DIR__"obj/erduo" );
		ob->move( me );
		erduo = 0;
	}	
	else 
		command( "say 您来得太迟，小猪耳朵俺给送人了。" );
	return 1;
}