// Npc: /d/guiyun/npc/qianzhang.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;
int ask_me();

void create()
{
	set_name("老者", ({ "old man", "old" }));
	set("gender", "男性");
	set("age", 70);
	set("long","他身高八尺有余，白发白须，满面红光，太阳穴高高隆起。看起来身负绝技。\n");
	set("attitude", "friendly");
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set("combat_exp", 90000);
	set("shen_type", -1);
	set("shen", -300);
	set("str", 20);
	set("dex", 24);
	set("con", 19);
	set("int", 21);
	set("inquiry",([
		"name" : "我就是江湖上人称“铁掌水上飘”的裘千仞！",
		"裘千丈" : (: ask_me :),       
	]));
	setup();
	set("chat_chance",10);
	set("chat_msg",({
		"老者将一口大铁缸顶在头上，走出数步，身子微摆，缸中忽然泼出些水来。\n",
		"老者足不停步地从河面上走了过去，身形凝稳，河水只浸及小腿。\n",
		"老者盘膝而坐，双目微闭，嘴里正喷出一缕缕的烟雾，连续不断。\n",
	}));
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	say( "老者脸色大变：这么说你都知道了？我求你千万别告诉别人。我告诉你怎么过河。\n");
	write("老者说道：水下有暗桩，jump river即可过河。\n");
	say("老者急急忙忙地离开了。\n");
	this_player()->set_temp("guiyun_river", 1);
	destruct(this_object());
	return 1;
}

void unconcious()
{
	say("老者叫道：我裘千仞年纪老了，武功已大不如前，不过轻身功夫却还没丢荒。\n");
	say("老者叫道：今天暂且放过你，来日再算帐！\n");
	say("老者低头疾趋而去。\n");
	destruct(this_object());
}
