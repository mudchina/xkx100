// Room: /d/guiyun/shulin5.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

int do_zhai(string arg);
int do_sling(string arg);
int do_shake(string arg);
int do_climb(string arg);

void create()
{
	set("short", "树林深处");
	set("long",@LONG
这是一片小树林的深处。地面上绿草如荫，茂密地生长着。四周安
静得令人毛骨悚然，看来还是赶紧离开这里的为妙。树丛中有一棵老树
(tree)，相对于其它树显得十分的粗壮，树上的树叶(leaf)非常茂密，
有几只不知名的小鸟在其中窜来窜去。
LONG
);
	set("exits",([
		"southeast" : __DIR__"shulin4",
		"north"     : __DIR__"shulin7",
	]) );
	set("item_desc", ([
		"tree" : "一棵大树，枝叶茂密，看不清上面的情况。枝头挂满了野果，已经熟地要掉下来了。\n",
		"leaf" : "树叶松松地挂在树上，看上去很想把它摘下来。\n",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	set("stick_count", 3);
	setup();
}

void init()
{
	object room;

	add_action("do_sling", "sling");
	add_action("do_sling", "tan");
	add_action("do_sling", "shoot");
	add_action("do_sling", "she");
	add_action("do_shake", "shake");
	add_action("do_shake", "wave");
	add_action("do_shake", "yao");
	add_action("do_shake", "huang");
	add_action("do_strike", "strike");
	add_action("do_strike", "press");
	add_action("do_strike", "hit");
	add_action("do_strike", "pai");
	add_action("do_strike", "ji");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_zhai", "zhai");
	if (room = find_object(__DIR__"shushang"))
		tell_room(room, "透过树叶的缝隙，你看见" + this_player()->name() + "来到了树下。\n");
}

int do_zhai(string arg)
{
	object me = this_player();

	if (arg != "leaf" && arg != "shuye" && arg != "ye")
		return notify_fail("你要摘什么？\n");

	message_vision("$N伸手去够树上的叶子，发现手臂需要再长几十尺才行！\n", me);
	return 1;
}

int do_sling(string arg)
{
	object weapon, room, *ob;
	object me = this_player();
	int i, qi, level, qicost, temp, exp;
	string weapon_name;

	if (arg != "leaf" && arg != "shuye" && arg != "ye")
		return notify_fail("你要射什么？\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	weapon = me->query_temp("weapon");
	if (!weapon) {
		message_vision("$N对着树上的叶子运气，又蹦又跳试图把它摘下来，却始终没法够到。\n", me);
		return 1;
	}
	weapon_name = weapon->query("name");
	if (weapon->query("skill_type") != "throwing") {
		message_vision("$N用手中的" + weapon_name + "去够树上的叶子，却不够长。\n", me);
		return 1;
	}

	if (room = find_object(__DIR__"shushang"))
	{
//		room = load_object(__DIR__"shushang");
		temp = 10 - me->query("str") / 5;
		if (temp < 1) temp = 1;
		if (!random(temp))
		{
			ob = all_inventory(room);
			for (i = 0; i < sizeof(ob); i++)
			{
				if (userp(ob[i]))
				{
					tell_object(ob[i], me->name() + "掏出一颗" + weapon_name + "，对着树上弹来，却正好击中你，你脚下一个不稳，掉了下去。\n");
					tell_room(room, me->name() + "掏出一颗" + weapon_name + "，对着树上弹来，却正好击中" + ob[i]->name() + "，" + ob[i]->name() + "脚下一个不稳，掉了下去。\n", ({ob[i]}));
					write("你掏出一颗" + weapon_name + "，对准树叶弹去，只听“啊”地一声惨叫，一个人从树上掉了下来，仔细一看，却是" + ob[i]->name() + "。\n");
					tell_room(this_object(), me->name() + "掏出一颗" + weapon_name + "，对准树叶弹去，只听“啊”地一声惨叫，一个人从树上掉了下来，仔细一看，却是" + ob[i]->name() + "。\n", ({me}));
					ob[i]->move(this_object());
					qi = ob[i]->query("qi");
					if (qi > 200) ob[i]->receive_damage("qi", qi / 2);
					else if (qi >= 100) ob[i]->receive_damage("qi", 100);
					else if (qi > 0) ob[i]->receive_damage("qi", qi);
					return 1;
				}
			}
		}
	}
	level = me->query_skill("throwing", 1);
	exp = me->query("combat_exp");
	qicost = level / 3 + random(level / 3);
        if (me->query("qi") <= qicost)
	{
		write("你太累了，先歇歇吧！\n");
		return 1;
	}
	if (level < 30)
	{
		write("你掏出一颗" + weapon_name + "，对准树叶弹去，却因为指劲太弱而没有弹到。\n");
		WEAPON_D->throw_weapon(me, me, weapon, 0);
		return 1;
	}
	me->receive_damage("qi", qicost);
	if (level <= 100)
	{
		write("你掏出一颗" + weapon_name + "，对准树叶弹去，只听“嗤”地声响过后，一片树叶应声而落。\n");
		WEAPON_D->throw_weapon(me, me, weapon, 0);
		if ( level * level * level /10 < exp)
			me->improve_skill("throwing", me->query("int"));
	}
	else {
		if (query("stick_count"))
		{
			message_vision("$N掏出一颗" +weapon_name+"，对准树叶弹去，结果用劲过大，连树枝都敲了下来，暗器功夫上却没有新进展。\n", me);
			add("stick_count", -1);
			new(__DIR__"obj/stick")->move(this_object());
		}
		else
			write("你掏出一颗" + weapon_name + "，对准树叶弹去，发现这样练习太轻松了，暗器功夫上已经无法取得新进展。\n");
		WEAPON_D->throw_weapon(me, me, weapon, 0);
	}
	return 1;
}

int do_shake(string arg)
{
	object room, *ob;
	object me = this_player();
	int i, qi, level, qicost, temp ,exp;

	if (arg != "tree" && arg != "shu" && arg != "dashu")
		return notify_fail("你要摇什么？\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if (room = find_object(__DIR__"shushang"))
	{
//		room = load_object(__DIR__"shushang");
		temp = 7 - me->query("str") / 5;
		if (temp < 1) temp = 1;
		if (!random(temp)) {
			ob = all_inventory(room);
			for (i = 0; i < sizeof(ob); i++)
			{
				if (userp(ob[i]))
				{
					tell_object(ob[i],me->name()+"使劲地摇晃着大树，你脚下一个不稳，掉了下去。\n");
					tell_room(room, me->name()+"使劲地摇晃着大树，" + ob[i]->name() + "脚下一个不稳，掉了下去。\n", ({ob[i]}));
					write( "你使劲地摇晃着大树，忽听“哗啦”一声，一个人从树上掉了下来，仔细一看，却是" + ob[i]->name() + "。\n");
					tell_room(this_object(),me->name()+"使劲地摇晃着大树，忽听“哗啦”一声，一个人从树上掉了下来，仔细一看，却是"+ob[i]->name() + "。\n", ({me}));
					ob[i]->move(this_object());
					if (!random(3))
					{
						qi = ob[i]->query("qi");
						if (qi > 200) ob[i]->receive_damage("qi", qi / 2);
						else if (qi >= 100) ob[i]->receive_damage("qi", 100);
						else if (qi > 0) ob[i]->receive_damage("qi", qi);
					}
					return 1;
				}
			}
		}
	}
	level = me->query_skill("parry", 1);
	exp = me->query("combat_exp");
	qicost = level / 3 + random(level / 3);
        if (me->query("qi") <= qicost)
	{
		write("你太累了，先歇歇吧！\n");
		return 1;
	}
	if (level < 30)
	{
		write( "你使劲地摇晃着大树，大树却纹丝不动，你不禁想到那句“蚍蜉撼树”的成语来。\n");
		return 1;
	}
	if (level > 100)
	{
		write("你使劲地摇晃着大树，把树上的果子都摇得落到几丈开外去了。\n");
		return 1;
	}
	me->receive_damage("qi", qicost);
	if (!random(5))
		message_vision("$N使劲地摇着大树，从树上掉下几个果子来，砸向$N的头脸，$N赶忙伸臂架开。\n", me);
	else
		write( "你使劲地摇着大树，从树上掉下几个果子来，砸向你的头脸，你赶忙伸臂架开。\n");
	if ( level * level * level /10 < exp)
		me->improve_skill("parry", me->query("int"));
	return 1;
}

int do_strike(string arg)
{
	object room, *ob;
	object me = this_player();
	int i, qi, level, qicost, temp, exp;

	if (arg != "tree" && arg != "shu" && arg != "dashu")
		return notify_fail("你要拍什么？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");

	if (room = find_object(__DIR__"shushang"))
	{
//		room = load_object(__DIR__"shushang");
		temp = 9 - me->query("str") / 5;
		if (temp < 1) temp = 1;
		if (!random(temp))
		{
			ob = all_inventory(room);
			for (i = 0; i < sizeof(ob); i++)
			{
				if (userp(ob[i]))
				{
					tell_object(ob[i],me->name()+"一掌拍向大树，你脚下一个不稳，掉了下去。\n");
					tell_room(room, me->name()+"一掌拍向大树，"+ob[i]->name()+"脚下一个不稳，掉了下去。\n", ({ob[i]}));
					write( "你一掌拍向大树，忽听“哗啦”一声，一个人从树上掉了下来，仔细一看，却是" + ob[i]->name() + "。\n");
					tell_room(this_object(),me->name()+"一掌拍向大树，忽听“哗啦”一声，一个人从树上掉了下来，仔细一看，却是" + ob[i]->name() + "。\n", ({me}));
					ob[i]->move(this_object());
					if (!random(3))
					{
						qi = ob[i]->query("qi");
						if (qi > 200) ob[i]->receive_damage("qi", qi / 2);
						else if (qi >= 100) ob[i]->receive_damage("qi", 100);
						else if (qi > 0) ob[i]->receive_damage("qi", qi);
					}
					return 1;
				}
			}
		}
	}
	level = me->query_skill("strike", 1);
	exp = me->query("combat_exp");
	qicost = level / 3 + random(level / 3);
        if (me->query("qi") <= qicost)
	{
		write("你太累了，先歇歇吧！\n");
		return 1;
	}
	if (level < 30)
	{
		write("你一掌拍向大树，大树却纹丝不动，你感到十分沮丧。\n");
		return 1;
	}
	if (level > 100)
	{
		write("你一掌拍向大树，把树上的果子都震得落到几丈开外去了。\n");
		return 1;
	}
	me->receive_damage("qi", qicost);
	if (!random(5))
		message_vision("$N一掌拍向大树，大树晃了几晃，$N对于自己的掌法更有自信了。\n", me);
	else
		write( "你一掌拍向大树，大树晃了几晃，你对于自己的掌法更有自信了。\n");
	if ( level * level * level /10 < exp)
		me->improve_skill("strike", me->query("int"));
	return 1;
}

int do_climb(string arg)
{
	object me = this_player();

	if (arg != "tree" && arg != "shu" && arg != "dashu" && arg != "up")
		return notify_fail("你要爬什么？\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	message_vision("$N往手心里啐了两口唾沫，运了运气，顺着树干爬了上去。\n", me);
	me->move(__DIR__"shushang", 1);
	message("vision", me->name() + "从树下爬了上来。\n", __DIR__"shushang", ({me}));
	return 1;
}

int valid_leave(object me, string dir)
{
	object room;
	int valid;

	valid = ::valid_leave(me, dir);
	if (valid && room = find_object(__DIR__"shushang"))
		tell_room(room,"透过树叶的缝隙，你看见"+me->name()+"离开了树下。\n");
	return valid;
}
