// little_monkey.c

inherit NPC;

void create()
{
	set_name("小猴",({ "little monkey", "monkey"}) );
	set("gender", "雄性");
	set("race", "走兽");
	set("age", 1);
	set("long", "这是一只调皮的小猴子，虽是畜牲，却喜欢模仿人样。\n");
	set("combat_exp", 500);
	set("shen_type", -1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "peaceful");
        setup();
}
