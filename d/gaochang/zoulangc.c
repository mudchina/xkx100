// Room: /d/gaochang/zoulangc.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;
string look_writing();

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是殿堂走廊。房顶一侧支在南面的高墙上，另一侧则与北边殿
堂的屋顶相连。彩梁画栋，抬眼望去，连顶棚也用彩漆绘满了各种
飞天的图形，每幅画似乎都在诉说一个娓娓动人的故事。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"zoulange",
		"southwest" : __DIR__"zoulangw",
		"north" : __DIR__"mishi",
	]));
	set("objects", ([
		__DIR__"npc/wuaer": 1,
	]));      
	set("item_desc",([
		"writing" : (: look_writing :),
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && (me->query_cor()<25) && !wizardp(me))
		return notify_fail("\n突然之间，前面一个阴森森的声音喝道：
「我在这里已安安静静的住了一千年，谁也不敢来打扰我。那一个大胆过来，立刻就死！」
你只觉得心头一寒，脚下直哆嗦，再也往前走不了一步。\n ");
	return 1;
}

string look_writing()
{
	return
	"\n"
"              文文文文文文文文文文文文文文文文文\n"
"              文文文文文文文    文文文文文文文文\n"
"              文文文文文文文文    文文文文文文文\n"
"              文文                          文文\n"
"              文文文文文  文文文文文  文文文文文\n"
"              文文文文文文  文文文  文文文文文文\n"
"              文文文文文文文  文  文文文文文文文\n"
"              文文文文文文文    文文文文文文文文\n"
"              文文文文文文  文文  文文文文文文文\n"
"              文文文文文  文文文文  文文文文文文\n"
"              文文文    文文文文文文    文文文文\n"
"              文    文文文文文文文文文    文文文\n"
"              文文文文文文文文文文文文文文文文文\n"
"              文文文文文文文文文文文文文文文文文\n";
}

void init()
{
	add_action("do_study", "yanxi");
}


int do_study(string arg)
{
	object me = this_player();
	int cost=10;

	if ( !arg && ( arg != "qiang" ) && ( arg != "qiangbi" ) )
		return notify_fail("什么？\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if((int)me->query("jing") < 30)
		return notify_fail("你现在精神无法集中！\n");

	me->receive_damage("jing", 10);

	message_vision("$N正专心研读墙壁上的古怪图形。\n", me);

	if ( (int)me->query_skill("literate", 1) < 100)
	{
	     if ((int)me->query("jing")>cost)
	      {
	      	me->improve_skill("literate", (int)(me->query("int")/4));
		write("你对着墙壁琢磨了一回儿，似乎对读书识字有点心得。\n");
		me->set_temp("stone_learned",1);
	       }
	     else
	       {
		cost=me->query("jing");
		write("你现在过于疲倦，无法专心下来研读读书识字。\n");
	       }
	}

	if ( !me->query_temp("stone_learned") )
	{
		write("你对着墙壁琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
	}
	return 1;
}

