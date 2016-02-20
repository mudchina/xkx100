// 天铃鸟
inherit NPC;
void create()
{
        set_name("天铃鸟", ({ "tianlin niao", "bird" }) );
	set("race", "飞禽");
	set("age", 1);
        set("long", "一只美丽的天铃鸟，鸟儿的歌声像是天上的银铃。
这鸟儿只在晚上唱歌，白天睡觉。有人说，这是天上的星星掉下来之後变的。\n");
        set("attitude", "friendly");
        set("max_qi", 100);
        set("max_jing", 100);
        set("eff_jingli", 100);	
	set("limbs", ({ "嘴", "翅膀", "爪子" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("combat_exp", 100);
	set("chat_chance", 30);
	set("chat_msg", ({ (: random_move :),}) );
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 5);
        set("senlin", 1);
	setup();
}
