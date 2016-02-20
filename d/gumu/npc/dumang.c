// Room: /d/gumu/npc/dumang.c
// Last Modifyed by Winder on Jan. 14 2002

inherit NPC;

void create()
{
        set_name("毒蟒", ({ "du mang", "mang" }));
	set("race", "爬蛇");
        set("age", 200);
        set("long", "一条庞大无比, 色彩斑斓的巨蟒。 浑身发出阵阵强烈的腥臭味。\n");
        set("attitude", "aggressive");
        set("str", 70);
        set("con", 50);
        set("max_qi", 800);
        set("combat_exp", 200000);
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 50);
        setup();
}

