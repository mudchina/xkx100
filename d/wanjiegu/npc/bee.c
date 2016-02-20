// bee.c
inherit NPC;

void create()
{
        set_name("ÃÛ·ä", ({ "bee" }) );
	set("race", "À¥³æ");
	set("subrace", "·É³æ");
        set("age", 1);
        set("long", "Ò»Ö»·è¿ñµÄÉ±ÈË·ä¡£\n");

        set_skill("dodge", 50);
        set("combat_exp", 500);
        set("bellicosity", 3000 );

        setup();
}
