// kang.c 康亲王

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
int ask_meili();

void create()
{
	set_name("杰书", ({ "jie shu", "jie", "shu"}));
	set("gender", "男性");
	set("title", HIY"康亲王"HIR"镶红旗旗主"NOR);
	set("age", 42);
	set("str", 25);
	set("dex", 20);
	set("long", "\n只见他一身锦衣，笑容满面，任谁见了他都生不起气来。\n"+
		"此人深谙为官之道，极善察言观色、溜须拍马，颇得皇帝欢心。\n");
	set("combat_exp", 50000);
	set("score", 5000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 25);
	set("qi", 500);
	set("max_qi", 500);
	set("jing", 300);
	set("max_jing", 300);
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 50);
	set("inquiry", ([
		"鳌拜" :  "\n鳌拜这厮横行霸道，我早就想除了他。\n",
		"玉骢马" :  "\n你想要我就送与你吧，不过它可不一定会服你。\n",
		"魅力" :  (: ask_meili :),
		"当官" : (: ask_meili :),
	]) );

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("gold", 5);
}

int ask_meili()
{
	command("tell "+this_player()->query("id")+" 你现在的魅力值是 " +(string)(this_player()->query("meili")));
	say("\n康亲王笑道：要想当官魅力不高可不行啊。\n");
	say("康亲王又说：多跟达官显贵们交往，魅力自然会提高的。\n");
	return 1;
}

void init()
{
	object ob = this_player();
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
}

void greeting(object ob)
{
	int i;
	object man,*obj;

	if( !ob || environment(ob) != environment() ) return;
	if (file_name(environment(ob)) != "/d/beijing/shufang") return;
	if((int)ob->query("meili")<20)
	{
		if(userp(ob))
			message_vision("\n康亲王一见$N, 顿时勃然大怒，叫道：“来人啊！将这厮给我拿下！”\n",ob);
			if(!present("shi wei", environment(ob)))
			{
				message_vision("登时门外冲进几个侍卫，挥刀向$N直扑过来。\n",ob);
				man=new("/d/huanggong/npc/shiwei");
				man->move(environment(ob));
				man=new("/d/huanggong/npc/shiwei");
				man->move(environment(ob));
				man=new("/d/huanggong/npc/shiwei");
				man->move(environment(ob));
			}
			return ;
	}
	switch( random(5) )
	{
		case 0:
			message_vision("\n$N刚一进门, 康亲王便抢着迎了出来，笑道：“这位"+RANK_D->query_respect(ob)+"，请进请进。\n",ob);
			if(ob->query("meili")<60)
			{
				ob->add("meili",10);
				message_vision(HIC"$N的魅力值提高了！\n"NOR,ob);
				command("tell "+ob->query("id")+" 你现在的魅力值是 " +(string)(ob->query("meili")));
			}
			break;
		default:
			say("康亲王笑道：不知这位" + RANK_D->query_respect(ob)+"，光临寒舍有何贵干？\n");
			break;
	}
}
