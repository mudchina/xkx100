// Npc: /d/kunlun/npc/bigmonkey.c
// Last Modified by winder on Jun. 29 2001

inherit NPC;

void create()
{
	set_name("大白猿", ({ "yuan", "dabai yuan", "big monkey" }) );
	set("gender", "雄性");
	set("race", "走兽");
	set("age", 65);
	set("long","这是一只大白猿，奇怪的是从它身上闻得到一阵腐臭之气，\n原来白猿肚上脓血模糊，生著一个大疮。\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("water", 200);
	set("food", 200);
	set("apply/attack", 100);
	set("apply/defense", 100);

	set_skill("unarmed", 25);
	set_skill("parry", 20);
	set_skill("dodge", 20);
	set("bag_count",1);

	setup();
}
void init()
{
	add_action("do_lifeheal", "lifeheal");
}
int do_lifeheal(string arg)
{
	object weapon, bag, me = this_player();
	if (query("bag_count")<1)
	{
		write("白猿一把跳开，不想让你医治！\n");
		return 1;
	}
	if( !arg || arg != "yuan")
	{
		write("你想干什么呀？\n");
		return 1;
	}
	if (!present("fish bone", me))
	{
		write("怎麽，管开刀不管缝肚皮啊！\n");
		return 1;
	}
	if (!objectp(weapon = me->query_temp("weapon")) ||
		((string)weapon->query("skill_type") != "sword" &&
		(string)weapon->query("skill_type") != "blade"))
		return notify_fail("你没有工具怎麽给它做手术！\n");

	message_vision(
"$N割开右边及上端的缝线，再斜角切开早已联结的腹皮，只见它肚子
里藏著一个油布包裹。$N将油布包放在一边，以鱼骨做针，在它腹皮
上刺下一个个小孔，再将树皮撕成细丝，穿过小孔打结，勉强将白猿
的腹肌缝好，在创口敷上草药。\n", me);
	bag = new(__DIR__"obj/bag");
	bag -> move (environment(me));
	add("bag_count",-1);
	return 1;
}
