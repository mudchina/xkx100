// Room: /d/wudujiao/huating3.c

inherit ROOM;

void create()
{
	set("short", "腾蛟亭");
	set("long", @LONG
这里是一个花园中的小亭子，雕梁画栋，古色古香。壁上挂着一幅
《少女月下舞剑图》(picture)。
LONG
	);
	set("outdoors", "wudujiao");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"huating1",
		"west" : __DIR__"huayuan3",
	]));
	set("item_desc",([
	    "picture":"只见画中少女手持钢钩，含笑而立。恍惚间你似乎觉得有无数道剑气扑面而来。\n这里面似乎隐含着某种奥秘，你可以照着画中的姿势比划(bihua)一下看看\n\n",
]));
	set("coor/x", -44890);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_bihua", "bihua");
}

int do_bihua(string arg)
{
	object weapon;
	object me=this_player();
	int hookskill=(int)me->query_skill("hook", 1);
	int maxlevel, exp=(int)me->query("combat_exp");

	if( !arg || arg != "picture")
		return notify_fail("你乱比划什么？\n");
	if( me->query("qi") < (int)(me->query("max_qi")/5))
		return notify_fail("再练下去你会累死的！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "hook")
		return notify_fail("不拿钩剑你乱比划什么？\n");
	if (!((string)me->query("family/family_name")=="五毒教"))
	{
		message_vision("$N照着壁上的画练了几次，累了一身臭汗。\n", me);
	}
	else
	{
		message_vision("$N手捻剑诀，依照画上少女的姿势练了一趟。\n", me);
		if (exp*10 <= (hookskill*hookskill*hookskill))
		{
			me->receive_damage("qi", 30);
			return notify_fail("你的经验不够，已经不能从画中领悟到什么了。\n");
		}
		if (hookskill < 150)
		{
			me->improve_skill("hook", random((int)(me->query("int") +me->query_skill("literate"))));
			tell_object(me, "你从中领悟出一些基本钩法方面的窍门。\n");
		}
		else
		{
			tell_object(me, "你费了半天劲，可是什么也没有学到。\n");
		}
	}
	me->receive_damage("qi", 30);
	return 1;
}

