// liping.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("李萍",({"li ping","li","ping"}));
	set("gender","女性");
	set("long","郭靖的母亲，流落在蒙古。\n");
	set("combat_exp", 6000);
	set("age", 43);
	set("max_qi", 800);
	set("qi", 800);
	set("food", 250);
	set("water", 250);
	setup();
	add_money("silver",5);
	carry_object("/clone/cloth/cloth")->wear();
}
