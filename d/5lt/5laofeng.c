// Room: /d/5lt/5laofeng.c

inherit ROOM;

int do_jump();

void create()
{
        set("short", "五老峰");
        set("long", @LONG
你感到寒意阵阵，原来已到了五老峰的峰顶。这里怪石嶙峋，最高
的地方一石卓立，你突然有种想跳上去(jump)一试身手的冲动。
LONG );
        set("exits", ([ /* sizeof() == 1 */
	    "westdown"  : __DIR__"shanlu",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -110);
	set("coor/y", 10);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump()
{
	object me;
	int i, ging_cost, qi_cost;
	
	me = this_player();
	i = (int)me->query_skill("dodge", 0) + random(5);
	ging_cost = 500 / (int)me->query("int");
	qi_cost = 400 / (int)me->query("int");
	
	if (me->is_busy() || me->is_fighting())
        	{
        		tell_object(me,"你正忙着呢。\n");
        		return 1;
        	}

	if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
		i = 0;

	message_vision("$N纵身一跃，在空中摆了个酷毙了的姿势。\n", me);
	me->start_busy(5);
	message_vision("只听『砰』地一声$N从空中跳了下来。\n", me);
	if ( i < 60)
		me->die();
	else if( i < 135)
		me->unconcious();
	else {
		message_vision("$N已稳稳地站在地上。\n", me);
		if( i > 210 && me->query_skill("dodge",1)<230)
			me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("jing", ging_cost );
		me->receive_damage("qi", qi_cost );
	}

	return 1;
}