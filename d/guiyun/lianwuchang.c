// Room: /d/guiyun/lianwuchang.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

int do_jump(string arg);
int do_squat();
string look_zhuang();

void create()
{
	set("short","练武场");
	set("long",@LONG
这是供归云庄内弟子们练功的场子。场边摆了两排兵器架，上面插
着各种兵器，最多的还是各式各样的剑。在场子的一个角落里并排竖着
两根半高的木桩(zhuang)，相距约一米，看起来是练功用的。西边是男
弟子休息室，而东边则是女弟子休息室。南边是吃饭和喝茶的地方。
LONG
);
	set("exits",([
		"west" : __DIR__"xiuxishi-m",
		"east" : __DIR__"xiuxishi-f",
		"north" : __DIR__"zoulang6",
		"south" : __DIR__"fanting",
	]) );
	set("objects",([
		"/clone/weapon/changjian" : 1,
		__DIR__"obj/mujian" : 1,
		__DIR__"npc/dizi-m" : 1,
		__DIR__"npc/dizi-f" : 1,
	]));

	set("item_desc",([
		"zhuang" : (: look_zhuang :),
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
	add_action("do_squat", "squat");
	add_action("do_squat", "dun");
}

int do_jump(string arg)
{
	object me = this_player();
	int level, qicost, exp;

	if (me->is_busy())
		return notify_fail("你上一个动作还没有完成！\n");
	level = me->query_skill("dodge", 1);
	exp = me->query("combat_exp");
	if (arg == "zhuang")
	{
		if (me->query_temp("thd_zhuang"))
		{
			write("你已经在桩上了，别是站久了头昏吧？\n");
			return 1;
		}
		qicost = level / 3 + random(level / 3);
		if (me->query("qi") <= qicost)
		{
			write("你太累了，先歇歇吧！\n");
			return 1;
		}
		if (level < 20)
		{
			write("你耸身作势，向桩上跃去，可惜的是脚尖还差一些才能够到。\n");
			return 1;
		}
		me->receive_damage("qi", qicost);
		if (level < 60)
		{
			message_vision("$N吸了口气，纵上了木桩，这似乎是锻炼轻功的好方法。\n", me);
			if (level * level * level / 10 < exp)
				me->improve_skill("dodge", me->query_int() / 2);
		}
		else
			message_vision("$N脚下微一运劲，轻轻地一纵就上了木桩，这两根木桩对$P而言也太矮了。\n", me);
		me->set_temp("thd_zhuang", 1);
		me->start_busy(random(2)+1);
		return 1;
	}
	if (arg == "down")
	{
		if (!me->query_temp("thd_zhuang"))
		{
			message_vision("$N想挖个坑跳进去，四处比划了一番，却发现周围的人都用异样的眼光看着自己。\n", me);
			return 1;
		}
		qicost = level / 4 + random(level / 4);
		if (me->query("qi") <= qicost)
		{
			write("你太累了，先歇歇吧！\n");
			return 1;
		}
		me->receive_damage("qi", qicost);
		if (level < 60)
		{
			message_vision("$N笨手笨脚地从桩上跌了下来，发现这很象是普通轻功的一式“平沙落雁”。\n", me);
			if (level * level * level / 10 < exp)
				me->improve_skill("dodge", me->query_int() / 5);
		}
		else
			message_vision("$N轻轻一纵落到了地上，觉得这两根木桩对$P而言也太矮了。\n", me);
		me->start_busy(random(2)+1);
		me->delete_temp("thd_zhuang");
		return 1;
	}
	return notify_fail("你要往哪里跳？\n");
}
	
int do_squat()
{
	object me = this_player();
	int level, qicost, exp;

	if (me->is_busy())
		return notify_fail("你上一个动作还没有完成！\n");
	level = me->query_skill("leg", 1);
	exp = me->query("combat_exp");
	qicost = level / 3 + random(level / 3);
	if (!me->query_temp("thd_zhuang"))
	{
		message_vision("$N刚往地上一蹲，就有个庄丁飞跑过来，大声喝道：“不准随地大小便！”\n", me);
		return 1;
	}
	if (me->query("qi") <= qicost)
	{
		write("你太累了，先站会儿喘喘气吧！\n");
		return 1;
	}
	if (level < 30)
	{
		write("你试着蹲下来，却觉得两腿发软，随时有跌下去的危险，连忙又站直了身子。\n");
		return 1;
	}
	if (level < 100)
	{
		write("你双腿成马步，挺胸收腹，以站桩姿势蹲了下来。\n");
		write("蹲了许久，你的双腿都快木了，只好站起来活动一下。\n");
		if (level * level * level / 10 < exp)
			me->improve_skill("leg", me->query_int());
		me->receive_damage("qi", qicost);
		me->start_busy(random(2)+1);
		if (!random(8))
			tell_room(this_object(), me->name() + "双腿成马步，挺胸收腹，以站桩姿势蹲了一会。\n", ({me}));
	}
	else
		write("你用力往下一蹲，只听木桩“吱嘎”作响，看来你的腿劲过大了。\n");
	return 1;
}

string look_zhuang()
{
	if (this_player()->query_temp("thd_zhuang"))
		return "你往脚下的木桩看去，觉得有点晕眩，刚才在地上看时好象没有这么高！\n";
	else
		return "木桩离地大概一米左右，普通人难以跳上去。\n";
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("thd_zhuang"))
		return notify_fail("先从木桩上跳下来(down)再说吧！\n");

	if (dir == "west" && me->query("gender") != "男性")
		return notify_fail("你打开门正要往里走，忽然发现里面都是光膀子的男弟子，你赶忙捂着脸退了出来。\n");

	if (dir == "east" && me->query("gender") != "女性")
		return notify_fail("你打开门正要往里走，却听到里面传来一阵女弟子的尖叫声，你吓得赶忙退了出来。\n");
	return ::valid_leave(me, dir);
}
