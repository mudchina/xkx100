// kejiaren.c 客家人
// Last Modifyed by Ahda on Jan. 4 2002

inherit NPC;

void create()
{
	int age;
	age = 20 + random(40);
	
	set_name("客家人", ({ "kejiaren", "kejia", "ren", }));
	set("gender", "男性");
	set("age", age);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 150+age*10);
	set("shen_type", 1);
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

