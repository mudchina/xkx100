// cooker.c
inherit NPC;
void  create()
{
	set_name("大师傅", ({ "da shifu" }));
	set("gender", "男性");
	set("age", 50);
	set("per", 15);
	set("long", "一位远近闻名的大师傅。天下八大菜系，都是他玩剩下的。\n");
	set("combat_exp", 100);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

