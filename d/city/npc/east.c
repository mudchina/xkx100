// east.c 东家西施

inherit NPC;

void create()
{
	set_name("西施", ({ "xishi"}));
	set("age", 15);
	set("gender", "女性");
	set("title", "东家");
	set("long", "她就是西施，虽然她倾城倾国的，可是垒的城墙可一点也不倾。\n");
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
