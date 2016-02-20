// wolf.c
// Date: Sep. 5 2000

inherit NPC;

void create()
{
	set_name("母狼", ({ "mu lang", "wolf", "lang" }) );
	set("race", "走兽");
	set("age", 5);
	set("gender", "雌性");
	set("long", "一只母狼，半张着的大嘴里露着几颗獠牙。\n");
	set("attitude", "peace");
	set("shen_type", -1);

	set("combat_exp", 20000);
	set_temp("apply/attack", 2000);
	set_temp("apply/defense", 3000);
	set_temp("apply/armor", 800);

	setup();

	set("chat_chance", 10);
	set("chat_msg", ({
		"母狼耷邋着尾巴，突然抬头，冲你发出一声凄厉的长嚎。\n",
		"母狼闪着绿幽幽的眼光冲你瞄了瞄，血盆巨口里答答滴着哈喇子。\n",
	}) );
}

