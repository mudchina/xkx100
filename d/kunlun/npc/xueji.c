// Npc: /d/kunlun/npc/xueji.c
// Last Modified by winder on Jun. 29 2001

inherit NPC;

void create()
{
	set_name("Ñ©¼¦", ({ "xue ji","ji" }) );
	set("race", "·ÉÇÝ");
	set("age", 2);
	set("long", "Ò»Ö»·Ê·Ê°×°×µÄÑ©¼¦¡£\n");

	set("combat_exp", 100);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 10);

	setup();
}

void die()
{
       object ob;
       message_vision("$N²Òº¿Ò»Éù£¬ÂýÂýµ¹ÏÂËÀÁË£¡\n", this_object());
       ob = new(__DIR__"obj/xueji-rou");
       ob->move(environment(this_object()));
       destruct(this_object());
}
