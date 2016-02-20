//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("乡农", ({"xiang nong", "nong"}));
	set("long", "一个乡下农民，黑黝黝的面庞，肩膀上搭了块脏兮兮的破汗巾。\n");
	set("gender", "男性");
	set("age", 24);
	set("combat_exp", 500);
	set("str", 24);
	set("int", 15);
	set("dex", 18);
	set("con", 22);
	set("per", 20);
  
	setup();
	carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/jiangling/obj/chutou")->wield(); 
}


