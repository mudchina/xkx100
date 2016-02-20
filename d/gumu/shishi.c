// shishi.c 石室
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
这是一间石室，室中点著灯火。石室奇小，两人站著，转身就很不
容易，室顶又矮，伸长手臂，几可碰到。在石室角落里有一只不大的布
袋(budai) ，绳索绑着袋口，蠕蠕而动，不知道是什么东西。
LONG );
	set("exits", ([
		"north" : __DIR__"mudao16",
	]));
	set("item_desc", ([
		"budai": "一只旧布袋，里面还蠕蠕而动着。\n"
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", -60);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_open", "dakai");
	add_action("do_open", "open");
	add_action("do_zhua", "zhua");
	add_action("do_zhua", "catch");
}

int do_open(string arg)
{
	object obj, me=this_player();
	if( !arg || arg != "budai" )
	{
		return notify_fail("你要打开什么？\n");
	}
	if (this_object()->query("opened"))
		return notify_fail("布袋已被打开了。里面啥也没有了。\n");
	message_vision("$N俯身在石室角落里提起一只布袋，解开缚在袋口的绳索，倒转袋子一抖，飞出来三只麻雀。\n",me) ;
	this_object()->set("opened", 1);
	obj=new(__DIR__"npc/maque");
	obj->move(this_object());
	obj=new(__DIR__"npc/maque");
	obj->move(this_object());
	obj=new(__DIR__"npc/maque");
	obj->move(this_object());
	return 1;
}

int do_zhua(string arg)
{
	object me=this_player();
	int c_exp, c_skill;

	c_exp=me->query("combat_exp");
	c_skill=(int)me->query_skill("yunv-shenfa", 1);
	if( !arg || arg != "ma que" ) return notify_fail("你要抓什么？\n");
	if( !objectp(present("ma que", environment(me))))
		return notify_fail("这里没有麻雀吧？\n");
	if( me->query("qi") < 30 )
		return notify_fail("你觉得太累了，不如歇会吧？\n");
	if( me->query_skill("yunv-xinfa", 1) < 10)
	{
		message_vision("$N的玉女心法不够娴熟，抓麻雀也没用。\n", me) ;
		return 1;
	}
	me->receive_damage("qi", random(30));
	if( random((int)c_skill/10) + 1 < 2)
	{
		message_vision("$N扑过去就抓。可是麻雀灵便异常，东飞西扑，$N气喘吁吁，累得满头大汗，别说捉到，连羽毛也碰不到一根。\n", me);
		return 1;
	}
	message_vision("$N轻轻纵起，伸手处，正好逮住一只麻雀。\n", me);
	if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp && c_skill<101)
	{
		me->improve_skill("yunv-shenfa", random(me->query("dex")));
		tell_object(me,"你的玉女身法进步了！\n");
	}
	return 1;
}
