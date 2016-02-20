// snake.c
inherit NPC;
void create()
{
        set_name("毒蛇", ({ "snake", "she" }) );
	set("race", "爬蛇");
        set("age", 4);
        set("long", "一只有着三角形脑袋的蛇，尾巴沙沙做响。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("cor", 30);
        set("combat_exp", 1000);
        set("max_qi",300);
        set("qi",300);
        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);
        setup();
}
