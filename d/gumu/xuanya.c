// Room: /d/gumu/xuanya.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"悬崖"NOR);
	set("long", @LONG
此处已是终南山绝路，光秃秃的石壁，下面则是云雾弥漫的万丈深
崖(xuanya)，传闻中有个古墓弟子因受不了古墓之清苦寡欲，从此处一
跃而下，了却一生。近悬崖边有棵摩天大树(tree)，枝叶极盛，如大伞
一张遮掩住方圆之地。
LONG	);
	set("outdoors","gumu");
	set("exits", ([
		"west" : __DIR__"mumen",
	]));
	set("item_desc", ([
		"xuanya" : "悬崖下一片云雾缭绕。跳(tiao)下去恐是有去无回。\n",
		"tree"   : "一棵高大的巨树，上面留下曾经被人摇晃的痕迹。\n", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -3220);
	set("coor/y", 40);
	set("coor/z", 90);
	setup();
}

void init()
{
	object room, me = this_player();

	if (random(me->query("kar")) >= 15 )
	{
		if(!( room = find_object(__DIR__"tree")))
			room = load_object(__DIR__"tree");
		if(!(present("du mang", room))) return;
		message_vision(HIR "突然闻到一股腥臭之气，大树上倒悬下一条碗口粗细的三角头巨蟒，把$N卷走了。\n\n"NOR, me);
		me->move(__DIR__"tree");
		me->start_busy(3);
	}
	else
	{
		add_action("do_tiao", "tiao"); 
		add_action("do_yao", "yao");
		add_action("do_climb", "climb");
		add_action("do_climb", "pa");
	}
}

int do_tiao(string arg)
{ 
	object me = this_player();

	if ( arg == "xuanya")
	{
		if (me->query_temp("mark/jump") < 2)
		{
			write("人生苦短，且古墓神功绝世，你再考虑一下吧。\n");
			me->add_temp("mark/jump", 1);
			return 1;
		}
		message_vision(HIR "$N纵身跳下悬崖，悲呼一声，兄弟姐妹们，来生再见，回声不绝于耳。\n"NOR, me);
		me->delete_temp("mark/jump");
		me->set_temp("last_damage_from", "跳崖自杀而");
		me->unconcious();
		me->die();
		return 1;
	}
	return notify_fail("你要跳到哪里？\n");
}

int do_yao(string arg)
{
	mapping fam;
	object me = this_player();
	int c_exp, c_skill;

	c_skill=(int)me->query_skill("parry", 1);
	c_exp=me->query("combat_exp");

	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("摇什么摇，没见过树啊？\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if (me->query("qi") < 30)
		return notify_fail("你累得够呛，去稍作歇息吧。\n");
	if (arg == "tree")
	{
		if (c_skill < 50)
			return notify_fail("你使出浑身的劲力，但是大树却纹丝不动。\n");
		if (c_skill > 100)
			return notify_fail("你使劲地摇晃大树，发现大树快被你摇断了。\n");
		write("你使劲地摇晃着大树，震的大树微微晃动。\n");
		me->receive_damage("qi", 10 + random(20));
		if (c_skill*c_skill*c_skill/10 < c_exp )
			me->improve_skill("parry", random(me->query("int")));
		return 1;
	}
	return notify_fail("你要摇什么？\n");
}

int do_climb(string arg)
{ 
	object me = this_player(); 

	if (arg == "tree")
	{
		message_vision(YEL"$N腾身往大树上爬去。\n"NOR, me);
		if (me->query_skill("dodge", 1) < 30)
		{
			message_vision(HIR"结果$N从树上一个筋斗掉下来。\n"NOR, me);
			me->receive_wound("qi", random(5) + 5);
			return 1;
		}
		message_vision(HIY"$N很快消失在浓荫密叶中。\n"NOR, me);
		me->move(__DIR__"tree");
		return 1;
	}
	write("你想往哪爬？\n");
}

