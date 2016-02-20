//ROOM xuanbing.c

inherit ROOM;

void init();
int do_climb(object me);
int do_xia(object me);
	
void create()
{
	set("short","玄冰室");
	set("long",@LONG
这是修练内功的地方。 屋子正中有一块千年玄冰(ice)，冰上冒出
丝丝寒气， 屋里因此寒气逼人，你不由得打了一个寒颤。
LONG );
	set("exits", ([
		"east" : __DIR__"changl13",
	]));
	set("item_desc", ([
		"ice" : "这是一块采自天山之巅的千年玄冰,据说在那上面打坐事半功倍.\n你可以试着爬(climb)上去.\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
}

int valid_leave(object me, string dir)
{
	object where;
	me=this_player();
	where=environment(me);
	if (dir == "east" && where->query("xuanbing"))
		return notify_fail("你还没下地(xia)呢，就想乱跑。\n");
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_xia", "xia");
}

int do_climb(object me)
{
	me=this_player();
	if(!me->query_skill("bahuang-gong", 1)||(int)me->query_skill("bahuang-gong", 1) < 10)
	{
		write("你的八荒六合唯我独尊功修为不够，抵御不了奇寒！\n");
		message_vision("$N费劲地爬上了玄冰，结果给冻得惨惨的，赶紧爬了下来。\n",me);
		return 1; 
 	}	
	message_vision("$N费劲地爬上了玄冰，现在打坐可以练功了。\n",me);
	set("xuanbing",1);
	return 1;	
}

int do_xia(object me)
{
	object where;
	me=this_player();
	where=environment(me);	
	if (!where->query("xuanbing"))
	 return notify_fail("你又没爬上玄冰，下到哪去呀？。\n");
	set("xuanbing",0);
	message_vision("$N练完功，精神焕发地跳下地来。\n",me);
	return 1;
}