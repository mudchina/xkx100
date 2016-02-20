// south.c 南家陈圆圆

inherit NPC;

void create()
{
	set_name("陈圆圆", ({ "chenyuanyuan"}));
	set("age", 40);
	set("gender", "女性");
	set("title", "南家");
	set("long","她就是陈圆圆。虽然后世认为丢了大明江山也有她的一点点干系，但她砌长城的本事却也不小。\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("per", 40);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	setup();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) ) command( "addin" );
}

