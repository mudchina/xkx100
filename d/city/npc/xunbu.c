// xunbu.c
#include <ansi.h>
#define THIEF 3
#define ROBBER 5
#define GO 0
#define BACK 1

inherit NPC;

int direction=GO;

mapping BigWay=([
	"/d/city/yamen":({"south",0}),
	"/d/city/tongsijie":({"east","north"}),
	"/d/city/caohexiaojie":({"east","west"}),
	"/d/city/tongsiqiao":({"east","west"}),
	"/d/city/shilijie4":({"north","south"}),
	"/d/city/shilijie4":({"east","west"}),
	"/d/city/shilijie3":({"north","south"}),
	"/d/city/shilijie2":({"north","south"}),
	"/d/city/shilijie1":({"north","south"}),
	"/d/city/shilijie5":({"north","south"}),
	"/d/city/shilijie6":({"east","south"}),
	"/d/city/shilijie7":({"east","south"}),
	"/d/city/ganquanjie": ({0,"west"}),
	"/d/city/nanmendajie": ({0,"north"}),
	"/d/city/beimendajie": ({0,"south"}),
]);

void create()
{
	string *surname=({"慕容","西门","公孙","上官","南宫","欧阳","司徒",});
	set_name(surname[random(sizeof(surname))]+"巡捕",({"xun bu","police"}));
	set("gender", "男性" );
	set("age", 25);
	set("str", 45);
	set("cor", 50);
	set("cps", 35);
	set("int", 20);
	set("per", 20);
	set("kar", 15);
	set("long",@LONG
巡捕个个身手矫健，强盗、山贼无不闻风丧胆。
LONG );
	set("status","patrol");
	set("CatchWho",0);
	set("combat_exp", 500000);
	set("attitude", "heroism");
	set("chat_chance", 3);
	set("chat_msg", ({
		"巡捕说道：你想干什么？还不跟我去府衙受审！？\n",
		"巡捕说道：大胆！居然敢当街拒捕！想造反？\n",
		"巡捕说道：别胡闹了，还是乖乖的跟我走吧。\n"
	}) );
	set ("inquiry",([
		"bribery":
			"说哪里话来，府太爷清贫廉正，我们作手下的岂能辱没他的名声？\n收起你的钱吧！\n",
		"salary": "哎，老爷俸银微薄，我们的年饷自然更少了......\n",
		"money": "说实在的，我也想要钱。但要是让老爷知道了我收受贿赂(bribery)，\n不死也得扒层皮\n",
	]));
	 set("pursuer",1);
	 set_skill("blade", 100);
	 set_skill("parry", 90);
	 set_skill("dodge", 70);
	 setup();
	 direction=GO;
	 carry_object("/clone/weapon/gangdao")->wield();
	 carry_object("/clone/misc/cloth")->wear();
	 add_money("silver",30);
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
	message_vision( "巡捕对着$N大喝一声：“大胆刁民，竟敢杀人放火，想置我们与何地？！！” \n", ob );
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

