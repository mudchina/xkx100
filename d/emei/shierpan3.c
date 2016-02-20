//Room: shierpan3.c 十二盘
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","十二盘");
	set("long",@LONG
这里石阶陡折多弯，号称「十二盘」。你见路边有个八音池，有人正在向
池中击掌(clap)。由此西上可达华严顶，东下则到万年庵。
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"eastdown"  : __DIR__"shierpan2",
		"southwest" : __DIR__"shierpan4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6160);
	set("coor/y", -1070);
	set("coor/z", 80);
	setup();
}
void init()
{
	add_action("do_clap", "clap");
}

int do_clap()
{
	object me = this_player();
	int c_exp,c_skill;
 
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("strike",1);
	write("池内忽然有蛙大鸣一声，接着群蛙次第相合，最后又是一蛙大鸣，群蛙便嘎然\n");
	write("而止，其数正好为八。\n");
	if ( me->query("qi") < 10 )
		 me->unconcious();
	else
	{
		if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill< 101)) 
		me->improve_skill("strike", (int)me->query_skill("strike", 1));
		me->receive_damage("qi", 10);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	int c_exp,c_skill;

	if (dir == "southwest" && userp(me))
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		if ( me->query("qi") < 10 ) me->unconcious();
		else
		{
			me->receive_damage("qi", 10);
			if (((c_skill*c_skill*c_skill/10)< c_exp) &&
				(c_skill < 101))
				me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
			tell_object(me,"你爬上了十二盘，觉得上山的路又陡又弯，好累人。\n");
		}
	}
	return 1;
}
