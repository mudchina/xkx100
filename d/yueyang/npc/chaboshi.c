// chaboshi.c ²è²©Ê¿þ

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("²è²©Ê¿", ({ "cha boshi", "chaboshi", "boshi" }) );
	set("gender", "ÄÐÐÔ" );
	set("age", 22);
	set("long", "ÕâÎ»²è²©Ê¿Ò»ÊÖÌá×Å´ó²èºø£¬Ò»ÊÖÁà×ÅÄ¨²¼£¬Ð¦ßäßäµØÃ¦×Å¡£\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("vendor_goods", ({
		__DIR__"obj/dongtingchun",
		__DIR__"obj/yinzhencha",
		__DIR__"obj/xianglian",
	}));
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "Ø¤°ï" 
		&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "µêÐ¡¶þÐ¦ßäßäµØËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob) + "£¬½øÀ´ºÈ±­²è£¬ÐªÐªÍÈ°É¡£\n");
			break;
		case 1:
			say( "µêÐ¡¶þÓÃ²±×ÓÉÏµÄÃ«½íÄ¨ÁËÄ¨ÊÖ£¬ËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob) + "£¬Çë½øÇë½ø¡£\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\nµêÐ¡¶þ´óºÈÒ»Éù£ºÄãÕâ³ôÒª·¹µÄ½øÀ´¸ÉÊ²÷á£¿¸øÎÒ¹ö³öÈ¥£¡\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/yueyang/nanjie");
	message("vision", "Ö»Ìý¡°Æ¹¡±µØÒ»Éù£¬" + ob->query("name") + "±»ÈË´Ó¶´±öÂ¥ÀïÒ»½ÅÌßÁË³öÀ´£¬ÀÇ±·Íò×´µÄÌÓ¿ªÁË¡£\n", environment(ob), ob);
}
