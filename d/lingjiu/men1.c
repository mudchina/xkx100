//ROOM men1.c

inherit ROOM;

void init();
//string look_door();
int do_open(string);

void create()
{
	set("short", "囚室大门");
	set("long",
"这是囚室东边，西面有一扇紧闭的大门(door)。\n"
);
	set("exits", ([
		"west" : __DIR__"qiushi",
		"east" : __DIR__"changl11",
	]));

	set("objects",([
		CLASS_D("lingjiu")+"/jujian" : 1,
	]));
	set("item_desc", ([
		"door" : (: look_door :),
	]));

	set_temp("lock",1);
//	set("no_clean_up", 0);
	set("coor/x", -51040);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
}

int valid_leave(object me, string dir)
{

	if ( (dir == "west") && objectp(present("ju jian", environment(me))) )
		return notify_fail("菊剑伸手拦住你，说道：“对不起，本门重地，请回！”\n");
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_open", "open");
}

string look_door(string arg)
{
	if (query_temp("lock") == 0)
		return "门上的铁锁已经被打开了。\n";
	return "这扇门被铁锁牢牢锁住。\n";
}

int do_open(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="door")
		return notify_fail("你要开什么？\n");
	
	if (me->is_busy()) return notify_fail("你正忙着呢。\n");

	if( query_temp("lock") == 1 && !present("key", me) )
		return notify_fail("钥匙都没有，怎么开门？\n");

	if(!( room = find_object(__DIR__"qiushi")) )
		room = load_object(__DIR__"qiushi");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'qiushi.c' \n");

	if(query_temp("lock") == 1 && present("key", me))
	{
		set_temp("lock", 0);
		message_vision("$N把钥匙插进锁孔，只听见‘卡嗒’一声，锁开了。\n", me);
		message("vision", "外面传来一阵开锁的声音，只听见‘卡嗒’一声，锁开了。\n",room);
	}
	message_vision("$N轻轻推开门，走了进去，随手把门掩了起来。\n",me);
	message("vision", "有人走了进来，随手把门掩上了。\n",room);
	me->move(room);
	return 1;
}