// Room: /d/taohua/tide.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "海中");
	set("long", @LONG
这里是水底，除了迎面扑来的潮水(tide)外你什么也看不见。
LONG
	);
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
	add_action("do_hit", "hit");
	add_action("do_hit", "ji");
}

int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
	if (arg != "bank" && arg != "anbian" && arg != "an" &&
		arg != "shore" && arg != "shatan")
		return notify_fail("你要往哪里跳？\n");

	me->move("/d/jiaxing/haibin");
	message_vision("$N忽然从海水里蹿了出来，在空中轻轻一转，落在了岸边。\n", me);
	return 1;
}

int do_hit(string arg)
{
	object me = this_player();
	object weapon;
	int hit_tide, temp;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (arg != "tide" && arg != "chao")
	{
		write("你要击打什么？\n");
		return 1;
	}
	if (!(weapon = me->query_temp("weapon")))
	{
		write("你对着海潮拳打脚踢了一阵，终于发泄了心中对本ＱＵＥＳＴ的不满。\n");
		return 1;
	}
	if (weapon->query("skill_type") != "sword")
	{
		write("你拿起" + weapon->query("name") + "对着海潮胡乱挥击了一阵，觉得自己特无聊。\n");
		return 1;
	}
	if (me->query("neili") < 60)
	{
		write("你的内力不足，无法继续练下去。\n");
		return 1;
	}
	if (me->query("qi") < 0)
	{
		write("你已经不行了，无法继续练下去。\n");
		return 1;
	}
	if (weapon->query("material") != "wood" || me->query("benefit/str"))
	{
		hit_tide = weapon->query_temp("hit_tide");
		if (hit_tide == 0)
		{
			if (weapon->query("material") == "wood")
				weapon->set_temp("max_hit_tide", 5);	
			else if (weapon->query("material") == "steel")
				weapon->set_temp("max_hit_tide", 12);	
			else
				weapon->set_temp("max_hit_tide", 8);	
		}
		write("你用" + weapon->query("name") + "奋力击打着海潮，于剑的运用方面有了一些领悟。\n");
		hit_tide++;
		if (hit_tide > weapon->query_temp("max_hit_tide")) {
			write("因为你用力过猛，"+ weapon->query("name") + "“啪”地一声折断了！\n");
			destruct(weapon);
		}
		else
			weapon->set_temp("hit_tide", hit_tide);
		me->receive_damage("qi", 45);
		me->add("neili", -40);
		if (me->query_skill("sword",1) < 80)
			me->improve_skill("sword", me->query("int") / 2);
		return 1;
	}
	else
	{
		hit_tide = me->query("sea/hit_tide");
		write("你用" + weapon->query("name") + "奋力击打着海潮，");
		hit_tide++;
		temp = hit_tide % 200;
		if (temp < 10)
			write(weapon->query("name") + "寂然无声。");
		else if (temp < 20)
			write(weapon->query("name") + "发出了轻微的声响。");
		else if (temp < 40)
			write(weapon->query("name") + "发出了嗤嗤的轻响。");
		else if (temp < 60)
			write(weapon->query("name") + "发出了刷刷的声音。");
		else if (temp < 80)
			write(weapon->query("name") + "发出了呼呼的声音。");
		else if (temp < 90)
			write(weapon->query("name") + "隐隐发出了轰轰的声音。");
		else if (temp < 110)
			write(weapon->query("name") + "竟然发出了轰隆隆的巨声。");
		else if (temp < 120)
			write(weapon->query("name") + "隐隐发出了轰轰的声音。");
		else if (temp < 130)
			write(weapon->query("name") + "发出了呼呼的声音。");
		else if (temp < 150)
			write(weapon->query("name") + "发出了刷刷的声音。");
		else if (temp < 170)
			write(weapon->query("name") + "发出了嗤嗤的轻响。");
		else if (temp < 190)
			write(weapon->query("name") + "发出了轻微的声响。");
		else
			write(weapon->query("name") + "寂然无声。");
		write("你对于内功以及剑法都有了一些领悟。\n");
		if (!(hit_tide % 20))
		{
			write("因为你用力过猛，"+ weapon->query("name") + "“啪”地一声折断了！\n");
			destruct(weapon);
		}
		me->set("sea/hit_tide", hit_tide);
		if (hit_tide >= 1400)
		{
			write("到了这个时候，你终于练到手中的木剑欲轻则轻欲响则响的境界！你的膂力增加了！\n");
			write("以后你恐怕无法再通过与海潮搏击而获得更深的内功修为了！\n");
			me->add("str",1);
			me->set("benefit/str", 1);
			me->delete("sea/hit_tide");
		}
		me->receive_damage("qi", 50);
		me->add("neili", -50);
		if (me->query_skill("sword",1) < 120)
			me->improve_skill("sword", me->query("int"));
		if (me->query_skill("force",1) < 120)
			me->improve_skill("force", me->query("int"));
		return 1;
	}
	return 1;
}
