// Room: /d/5lt/zhensuo2.c

inherit  ROOM;
int do_pull(string arg);

void  create  ()
{
	set  ("short",  "诊所二楼");
	set  ("long",  @LONG
这里就是布置简单的医生居室。几张简洁的小床，可以让任何人休息。总有护士
及时地更换被单枕头。养足精神后人们惬意的微笑就是对诊所主人最好的报答。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"down"  :  __DIR__"zhensuo",
	]));
	set("item_desc", ([
		"chuang" : "这是一张崭新的铁架床，床底下似乎还有些什么。\n" ,
		"床"     : "这是一张崭新的铁架床，床底下似乎还有些什么。\n" ,
		"xia"    : "你仔细看了一下木匣，发现里面似乎放着一本书。\n",
		"木匣"   : "你仔细看了一下木匣，发现里面似乎放着一本书。\n",
	]));
	set("coor/x", -140);
	set("coor/y", -30);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_move", "move");
        add_action("do_move", "nuo"); 
        add_action("do_pick", "pick");
}

int do_move(string arg)
{
	object me = this_player();

	if (!arg||arg!="chuang") return notify_fail("你要挪开什么？\n");
	if (me->query("neili") < 200)
	{
		message_vision("$N倚住床身，往旁一挪，铁架床纹风不动。\n", me);
		me->set("neili", 0);
		return 1;
	}
	if ( query("chuang") )
		return notify_fail("铁架床已经挪开了，再挪就到楼下去了！\n");
	message_vision("$N挪开铁架床，床下好像放着一个木匣(xia)。\n", me);
	set("chuang", 1);
	return 1;
}

void reset()
{
	::reset();
	set("get_available" , 1);
}

int do_pick(string arg)
{
	object me,obj;

	me = this_player();
	if( !arg || arg!="book" ) return notify_fail("你要拿什么？\n");
	if ( query("get_available") )
	{
		obj = new (BOOK_DIR+"medicine5");
		obj->move(me);
		add("get_available", -1);
		message_vision("$N从木匣中取出一本书。\n",me );
	}
	else
		return notify_fail("你要拿起那本书，却发现你看花了眼，其实那里什么都没有。\n");
	return 1;
}
