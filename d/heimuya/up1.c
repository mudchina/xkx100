// Room: /d/heimuya/up1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
int do_insert(string arg);
int do_enter(string arg);

void create()
{
	set("short", "日月坪");
	set("long", @TEXT
这里是半山的一片小土坪，离崖顶还有一段路途，可到这已经没有
路上去，面前是如境般的峭壁，仰头而望，但见崖顶依稀耸立着楼阁，
宛如仙境。可云烟缭绕，看不清晰。从悬崖上垂下一条绳索(rope)，看
上去象是悬崖上下互通消息的工具，绳索的上面似乎隐约挂有一个吊篮
(basket)。悬崖的墙上似乎有一个匣子(xiazi) ，你似乎走入一个雾宅，
真不知如何是好。
TEXT);

	set("exits", ([
		"eastdown" : __DIR__"shimen",
	]));
	set("outdoors", "heimuya");
	set("objects", ([
		CLASS_D("heimuya")+"/zhang1" : 1,
	]));

	set("item_desc", ([
		"basket" : "那是一个吊篮，看样子有些古怪。好象是装人的，你可以钻(enter)进去试试。\n",
		"rope"   : "绳子就是绳子，可能是向上的工具。\n",
		"xiazi"  : "这是一个匣子，看样子是一个开关，匣子的侧面有一个插孔。\n",
	]));
	set("coor/x", -3260);
	set("coor/y", 4200);
	set("coor/z", 60);
	setup();
}

void init()
{
	add_action("do_insert", "insert");
	add_action("do_enter", "enter");
}

void check_trigger()
{
	object room;

	if(!query("exits/enter") )
	{
		if( !(room = find_object(__DIR__"basket")) )
			room = load_object(__DIR__"basket");
		if( room = find_object(__DIR__"basket") )
		{
			if((int)room->query("insert_trigger")==0 )
			{
				room->set("insert_trigger", 1);
				set("exits/enter", __DIR__"basket");
				room->set("exits/out", __FILE__);
				message("vision","只见一个掉篮(basket)从天而降，你不禁一怔！\n" , this_object() );
				set("item_desc", ([
					"basket" : "这是一个掉篮，是传说中的交通工具。\n",
				]));
				remove_call_out("on_board");
				call_out("on_board", 15);
			}
			else
				message("vision", "看样子你得等下拨儿。\n",this_object() );
		}
		else
			message("vision", "ERROR: basket not found\n", this_object() );
	}
}

void on_board()
{
	object room;
	if( !query("exits/enter") ) return;
	message("vision","只见掉篮缓缓向上，四周无限美好，\n你似乎置身于一处人间仙境无异。\n", this_object() );
	if( room = find_object(__DIR__"basket") )
	{
		room->delete("exits/out");
	}
	delete("exits/enter");
	remove_call_out("arrive");
	call_out("arrive",20);
}

void arrive()
{
	object room;
	if( room = find_object(__DIR__"basket") )
	{
		room->set("exits/out", __DIR__"up2");
		message("vision","噔的一声，你似乎一下从天上到了地上。\n",room);
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room;
	if( room = find_object(__DIR__"basket") )
	{
		room->delete("exits/out");
		room->delete("insert_trigger");
	}
}

int do_insert(string arg)
{
	string dir;
	object ob, me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="卡" ) arg = "card1";   
	if( arg=="card1")
	{
		if( !objectp(ob = present(arg, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( !me->query_temp("mark/cards") )
			me->set_temp("mark/cards",1);
		if( me->query_temp("mark/cards")==4)
		{
			check_trigger();
			me->delete_temp("mark/cards");
		}
		else
		{
			me->add_temp("mark/cards",1);
			message("vision","噔的一声，你看到掉篮向下一节。\n",me);
		}
	}
	return 1;
}
int do_enter(string arg)
{
	object me = this_player();

	if( arg != "basket")
		return notify_fail("你要往那里钻？\n");
	if( me->query("family/master_id") != "dongfang bubai")
		return notify_fail("崖上传来一阵怪叫：不是东方教主座下弟子，不得到处乱钻！\n");
	message_vision("$N哈腰钻进竹篮，只听“嗖”地一声，竹篮被急速拉上崖去。\n", me);
	me->move(__DIR__"chengdedian");
	return 1;
}
