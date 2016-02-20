// cexiang.c 侧厢
// Java Oct.10 1998

inherit ROOM;
void back(object me);
void init();
int do_sleep(string arg);

void create()
{
	set("short", "侧厢");
	set("long", @LONG
这里是古墓中的侧厢房。房间里面黑呼呼的，什么东西都没有，只
有一条细绳(rope)，在室东的一根铁钉上系住，拉绳横过室中，绳子的
另端系在西壁的一口钉上，绳索离地约莫一人来高。
LONG );

	set("exits", ([
		"west" : __DIR__"mudao14",
	]));
	set("item_desc", ([
		"rope" : "一条细麻绳，看来是古墓弟子们睡眠之所。\n"
	]));
	set("no_clean_up", 0);
	set("coor/x", -3180);
	set("coor/y", -40);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
	object room, *ob, me=this_player();
	int i, j;

	if( !(room = find_object(__DIR__"rope")) )
		room = load_object(__DIR__"rope");
	if( !arg || arg != "rope" )
	{
		return notify_fail("你要睡在哪儿？\n");
	}
	if((int)me->query_skill("yunv-xinfa",1) < 10)
	{
		message_vision("$N的玉女心法不够娴熟，跳不上绳去。\n",me) ;
		return 1;
	}
	me->receive_damage("qi",random(30));
	ob = all_inventory(room);
	j = 0;
	for(i=0; i<sizeof(ob); i++)
		if( living(ob[i]) && ob[i] != me ) j++;
	if (j > 0)
	{
		message_vision("$N轻轻纵起，发现绳上有人，只好飞身下地。\n",me);
		return 1;
	}
	message_vision("$N轻轻纵起，横卧绳上，以绳为床，睡起觉来。\n", me);
	me->move(room) ;
	call_out("back", 6 , me);
	return 1 ;
}

void back( object me )
{
	int c_exp,c_skill;
	me->move(__DIR__"cexiang");
	message_vision("$N一觉醒来，飞身跃下绳来。\n",me);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("dodge",1);
	if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp && c_skill<101)
	{
		me->improve_skill("dodge",me->query("int"));
		tell_object(me,"你的基本轻功进步了!\n");
	}
}
