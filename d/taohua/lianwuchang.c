// Room: /d/taohua/lianwuchang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_jump(string arg);
string look_zhuang();

void create()
{
	set("short","练武场");
	set("long",@LONG
这是供桃花岛上弟子们练功的场子。场边摆了两排兵器架，上面插
着各种兵器，最多的还是各式各样的剑。在场子正中竖着一根很高的木
桩(zhuang)，看起来象是练功用的。北边是男弟子休息室，而南边则是
女弟子休息室。西边是弟子们吃饭和喝茶的地方。
LONG
);
	set("exits",([
		"north" : __DIR__"liangongfang",
		"south" : __DIR__"xiaowu",
		"east"  : __DIR__"zoulang3",
		"west"  : __DIR__"fanting1",
	]) );
	set("item_desc",([
		"zhuang" : (: look_zhuang :),
	]) );
	set("no_clean_up",0);
	set("valid_startroom", 1);
	set("outdoors","taohua");
	set("coor/x", 8980);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object me = this_player();
	int level, qicost;

	level = me->query_skill("dodge", 1);
	if (arg == "zhuang")
	{
		if (me->query_temp("thd_zhuang"))
		{
			write("你已经在桩上了，别是站久了头昏吧？\n");
			return 1;
		}
		qicost = level / 4 + random(level / 3);
		if (me->query("qi") <= qicost)
		{
			write("你太累了，先歇歇吧！\n");
			return 1;
		}
		if (level < 50)
		{
			write("你耸身作势，向桩上跃去，可惜的是脚尖还差一些才能够到。\n");
			return 1;
		}
		me->receive_damage("qi", qicost);
		if (level < 100)
		{
			message_vision("$N吸了口气，纵上了木桩，这似乎是锻炼轻功的好方法。\n", me);
			me->improve_skill("dodge", me->query_int());
		}
		else
			message_vision("$N脚下微一运劲，轻轻地一纵就上了木桩，这两根木桩对$P而言也太矮了。\n", me);
		me->set_temp("thd_zhuang", 1);
		return 1;
	}
	if (arg == "down")
	{
		if (!me->query_temp("thd_zhuang"))
		{
			message_vision("$N想挖个坑跳进去，四处比划了一番，却发现周围的人都用异样的眼光看着你。\n", me);
			return 1;
		}
		qicost = level / 5 + random(level / 4);
		if (me->query("qi") <= qicost)
		{
			write("你太累了，先歇歇吧！\n");
			return 1;
		}
		me->receive_damage("qi", qicost);
		if (level < 100)
		{
			message_vision("$N笨手笨脚地从桩上跌了下来，发现这很象是普通轻功的一式“平沙落雁”。\n", me);
			me->improve_skill("dodge", me->query_int() / 3);
		}
		else
			message_vision("$N轻轻一纵落到了地上，觉得这两根木桩对$P而言也太矮了。\n", me);
		me->delete_temp("thd_zhuang");
		return 1;
	}
	return notify_fail("你要往哪里跳？\n");
}

string look_zhuang()
{
	if (this_player()->query_temp("thd_zhuang"))
		return "你往脚下的木桩看去，觉得有点晕眩，怎么这木桩好象自己在长呀？！\n";
	else
		return "木桩离地大概三米左右，恐怕只有高手才能跳上去。\n";
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("thd_zhuang"))
		return notify_fail("先从木桩上跳下来(down)再说吧！\n");

	return ::valid_leave(me, dir);
}
