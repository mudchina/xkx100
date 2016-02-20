// shanyang.c

inherit NPC;

void create()
{
        set_name("山羊", ({ "shan yang" }));
        set("long","一头短角山羊，大理地区常见的家畜。\n");
	set("race", "走畜");
        set("age", 5);
        set("int", 30);
        set("qi", 300);
        set("max_qi", 300);
        set("jing", 100);
        set("max_jing", 100);
        set("shen_type", 0);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

        setup();
}

