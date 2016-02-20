//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("²Ë··", ({"cai fan", "fan"}));
	set("long", "Ò»¸öÂô²ËµÄĞ¡··£¬ÌôÁËÒ»µ£ÂÌÓÍÓÍµÄ¿ÕĞÄ²Ë¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 24);
	set("combat_exp", 1000);
	set("str", 24);
	set("int", 15);
	set("dex", 18);
	set("con", 22);
	set("per", 20);
  
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}


