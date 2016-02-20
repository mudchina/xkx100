// shuishi.c

inherit NPC;

void create()
{
	set_name("水师兵士",({ "shuishi bingshi","bingshi" }) );
	set("gender", "男性" );
	set("age", 12);
	set("combat_exp", 20000);
	set("shen", 100);
	set("shen_type", 1);
	set("str", 30);
	set("dex", 30);
	set("con", 30);
	set("int", 30);
	set("attitude", "friendly");
	set_skill("spear",50);
	set_skill("parry",50);
	set_skill("dodge",50);
	set_skill("unarmed",50);

	setup();
        carry_object("/clone/armor/tengjia")->wear();
        carry_object("/clone/weapon/changqiang")->wear();
}

