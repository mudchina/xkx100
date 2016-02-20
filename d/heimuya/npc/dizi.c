// jiaotu.c 日月神教教徒
#include <ansi.h>
inherit NPC;
void create()
{
	int age;
	age = 20 + random(10);	
	set_name("成德殿殿下弟子", ({ "dizi" }));
	set("gender", "男性");
	set("age", age);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);	
        set("apply/attack", 40);
	set("apply/defense", 40);
	set("apply/damage", 35);
	set("combat_exp", 5000+age*40);
	set("shen_type", -1);
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIW"教众"NOR);
	setup();
	add_money("silver", 10+age/10);
}	
void init()
{        object ob,me,what;
        ::init();
        ob = this_player();
        me = this_object();
        if( interactive(ob) && !is_fighting() ) 
        {
                remove_call_out("greeting");
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( "日月神教，日出东方，唯我不败。\n");
                        break;
                
        }
}
