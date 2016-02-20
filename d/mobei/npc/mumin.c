// mumin.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("蒙古牧民",({"mu min"}));
	set("gender","男性");
	set("long","铁木真部落中族人。\n");
	set("combat_exp",600);
	
	set("age",54);
	set("qi",600);
	set("max_qi",600);
	set("food",250);
	set("water",250);
	setup();
	add_money("silver",3);
	carry_object("/clone/armor/shoupi")->wear();
}
