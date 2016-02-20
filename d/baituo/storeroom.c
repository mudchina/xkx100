// Room: /d/baituo/storeroom.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void init();
int do_open(string);
string* obj = ({
	"/d/xingxiu/obj/fire",
	"/d/xingxiu/obj/hulu",
	"/clone/book/bt_book1",
	"/clone/book/bt_book2",
	"/clone/book/bt_book3",
	"/clone/book/bt_book5",
	"/d/baituo/obj/shepi1",
//	"/d/baituo/obj/yao",
//	"/d/baituo/obj/yao1",
//	"/d/baituo/obj/yao2",       
});

void create()
{
	set("short", "储藏室");
	set("long", @LONG
这是一个储藏室，四周密不透风。你一进门便闻到一股霉味，在门
外射进来的阳光的照耀下，你看见这里满屋的灰尘，成堆成堆的物品快
堆满了整间房间。你很是奇怪为什么仆役们离开时不把这些物品也带走。
只有关闭着的大门(door)。
LONG	);
	set("item_desc" , ([
		"door" : "一扇木门，也许能打开。\n",
	]) );
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("coor/x", -50000);
	set("coor/y", 20020);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_open","open");
	add_action("do_find", "find");
	add_action("do_find", "zhao");
	add_action("do_find", "fan");
}

int do_open(string arg)
{
	object me=this_player();
	object room;

	if( me->is_busy()) return notify_fail("你正忙着呢，没手开门。\n");
	if( !arg|| arg!="door") return notify_fail("你要开什么？\n");
	if(!( room = find_object(__DIR__"kongdi")) )
		room = load_object(__DIR__"kongdi");
	if(!objectp(room)) return notify_fail("ERROR:not found 'kongdi.c' \n");
	if(room->query_temp("lock")==1)
		return notify_fail("门已经从外面锁住了。\n");
	message_vision("$N轻轻推开门，走了出去，随手把门掩了起来。\n",me);
	message("vision", "有人走了出来，随手把门掩上了。\n",room);
	me->move(room);
	return 1;
}

int do_find()
{
	object me, ob;
	me = this_player();
	if( (int)me->query_temp("baituo_find") ) 
		return notify_fail("你已经发现东西了，拿了就走吧。\n");
	if (me->query_skill("hamagong", 1) > 10 &&
		me->query_skill("xidu-poison", 1) > 30)
	{
		message_vision("$N捏着鼻子在物品堆中乱翻着。\n", me);
		remove_call_out("found");
		call_out("found", 1, me);    
		return 1;
	}
	if (me->query_skill("xidu-poison", 1) < 50)
	{
		message_vision("$N捏着鼻子在物品堆中乱翻着。\n", me);
		if(random((int)me->query("kar")) < 15)
		{
			write("你吸了口气，突然觉得头中一阵眩晕。\n");
			me->unconcious();
			return 1;
		}
		else
		{
			remove_call_out("found");
			call_out("found", 1, me);    
			return 1;
		}
	}
	else
	{ 
		message_vision("$N捏着鼻子在物品堆中乱翻着。\n", me);
		write("你吸了口气，突然觉得头中一阵眩晕。。不好！你中毒了！\n");
		me->apply_condition("snake_poison", 22);
		me->unconcious();
		return 1;
	}
}

int found(object me)
{
	object ob;
	ob = new(obj[random(sizeof(obj))] );
	ob->move(environment(me));
	message_vision("$N翻了半天，找到了"+ob->query("name")+"。\n", me);
	me->set_temp("baituo_find", 1);
	return 1;
}

