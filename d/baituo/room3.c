// Room: /d/baituo/room3.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
int do_da(string arg);
void create()
{
	set("short","练功室");
	set("long", @LONG
这里是白驼山弟子的练功室。这个练功室空无一人，只有几个大大
的木桩(zhuang)立在屋子当中。
LONG	);
	set("exits",([
		"out" : __DIR__"liangong",
	]));
	set("item_desc", ([
		"zhuang":"一个木桩，做成木人的样子固定在地上，供人击打(da)练功。\n",
	]));     
	set_temp("full",0);
	set("no_clean_up", 0);
	set("coor/x", -49990);
	set("coor/y", 20030);
	set("coor/z", 30);
	setup();
}

void init()
{
	object ob=this_player();
	if((int)query_temp("full")==2)
	{
		message_vision("$N一见房间里已经有人了，只好退了出去。\n",ob);
		ob->move(__DIR__"liangong");
		return;
	}
	add_temp("full" ,1);
	add_action("do_da", "da");
	return;
}

int valid_leave(object who, string dir)
{
	add_temp("full",-1);
	return 1;
}
int do_da(string arg)
{
	object me = this_player();
	int jing1, qi1, exp, lvl;
	object weapon;

	exp = me->query("combat_exp");
	lvl = me->query_skill("staff",1);
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心练功！\n");
	if (!living(me)) return notify_fail("你发疯了？\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff")
		return notify_fail("空手是练不了杖法的。\n");
	if (!arg || arg!="zhuang") return notify_fail("你要打什么？打人吗？\n");
	jing1 = random((int)me->query("con"))+1;
	qi1 = random((int)me->query("str"))+1;
	if ((int)me->query("jing") < jing1 || (int)me->query("qi") < qi1)
	{
		message_vision("$N马步一松，一不小心脑袋撞在了木桩上！\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", jing1);
	me->receive_damage("qi", qi1);       
	message_vision("$N站好马步，提起钢杖，开始和木桩对打起来。\n", me);
	if ( lvl < 30 && lvl*lvl*lvl/10 < exp && random(10) > 4 )
	{
		me->improve_skill("staff", (int)(me->query("int") / 5));
	}
/*
	if ( (int)me->query("combat_exp") < 30000) 
	{
		me->add("potential",random(2));
		me->add("combat_exp",random((int)(me->query("int") / 10)));
	}
*/
	return 1;
}

