// chacha.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
	HIW "判官用奇异的眼光盯着你，好像要看穿你的一切似的。\n\n" NOR,
	HIW "判官对你说道：喂！该你了！\n\n" NOR,
	HIW "判官「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n" NOR,
	HIW "判官合上册子，说道：嗯，你阳寿未尽，怎么跑到这里来了？\n\n" NOR,
	HIW "判官搔了搔头，叹道：罢了罢了，你还是回阳间吧。\n\n"
		"一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});

void create()
{
	set_name(YEL "判官" NOR, ({ "pan guan","guan" }) );
	set("long", @LONG
地狱阴司中执掌管带众鬼，以施奖惩之官，手中拿着记载人寿命的生死簿。
LONG);
	set("gender","男性");
	set("str",1000);
	set("title",HIW "查察司" NOR);			
	set("attitude", "peaceful");
	set("age", 1000);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
	set("max_neili",10000);
	set("neili",10000);
	setup();
	carry_object( __DIR__"obj/shsbu" )->wear();
}


void init()
{
	object ob;
	::init();
	if( !(ob=previous_object())||!userp(ob)) 
		return;
	if(!ob->is_ghost() && !wizardp(ob)) 
	{
		command("say 喂！阳人来阴间做什麽？");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}
	call_out( "check_rein",2, ob);
}

void check_rein(object ob)
{
	int mud_age, rein_time;
	mud_age=(int)ob->query("mud_age");
	rein_time=(int)(ob->query("PKS") * 20) + (int)(ob->query("MKS") / 10);
	if((int)ob->query("age")<=15 || mud_age>=rein_time)
	{
		remove_call_out("death_stage");
		call_out("death_stage" ,1,ob,0);
	}
}

void death_stage(object ob, int stage)
{
	object *obs, mailbox;
	int i;

	if( !ob || !present(ob) ) return;
	if( stage != 4 )
		tell_object(ob, death_msg[stage]);
	else
	{
		obs = deep_inventory(ob);
		if(sizeof(obs))
		{
			command("hmm");
			tell_object(ob,HIW"判官说道：“不过阴间的东西是不能带到阳间的，你先要把你身上的东西放下来。”\n"NOR);
			return;
		}
		else
			tell_object(ob,death_msg[stage]);
	}
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 3, ob, stage );
		return;
	}
	ob->reincarnate();
	obs = all_inventory(ob);
	for (i = 0; i < sizeof(obs); i++)
		DROP_CMD->do_drop(ob, obs[i]);
	if (!mailbox=present("mailbox",ob))
	mailbox = new("/clone/misc/mailbox");
	mailbox->move(ob);
  if (time()-ob->query_temp("LAST_PKER_TIME")<7200)
       ob->move("/d/city/shilijie4");
   else
      ob->move(REVIVE_ROOM);
	message("vision",
		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
		"很久了，只是你一直没发觉。\n", environment(ob), ob);
}

