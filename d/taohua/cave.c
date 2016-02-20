// Room: /d/taohua/cave.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
int do_pull(string arg);

void create()
{
	set("short", "岩洞");
	set("long", @LONG
这里是一个山壁上的小岩洞，虽然不甚宽敞，但也有足够的活动空
间。阳光透过桃树间的缝隙射了进来，映得洞中半明半暗。只能隐隐约
约看出地上有一堆干草。干草上好象放着一个石匣 (xia)。靠里的洞壁
上依稀写有一行小字(zi)。
LONG
	);
	set("exits",([
		"out" : __DIR__"dongkou",
	]) );
	set("no_clean_up",0);
	set("item_desc",([
		"xia" : "你仔细看了一下石匣，发现里面似乎放着一本书。\n",
		"zi": "只见洞壁上用尖利之物刻着字道：“奉上臭尿数罐，请啊请啊....”，后面的字被一片树叶(ye)盖了起来。\n",
		"ye": "一片普通的树叶，把下面的字全都遮住了。\n",
	]) );
	set("objects",([
		__DIR__"npc/zhou" : 1,
	]) ); 
	set("coor/x", 9210);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_pull","pull");
	add_action("do_pull","che");
	add_action("do_pull","move");
	add_action("do_pull","yi");
	add_action("do_pick","pick");
}

int do_pull(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (arg == "ye")
	{
		message_vision("$N伸手揭起树叶，猛听得头顶忽喇喇声响，立时醒悟，忙向一旁跃开，哪知乒乒乓乓一阵响亮，从洞顶上掉下几只瓦罐，淋了$N一头臭尿。\n",me);
		return 1;
	}
	return 0;
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
	if ( present("zhou botong",environment(me)))
	
	{
		message_vision(YEL "周伯通两眼一瞪，哼了一声道：别在我这里偷偷摸摸！我周伯通还没死哪！\n" NOR,me) ;
		return 1 ;
	}
	if ( query("get_available") )
	{
		obj = new (BOOK_DIR+"jiuyin1");
		add("get_available", -1);
		if (obj->violate_unique())
		{
			destruct(obj);
			return notify_fail("你要拿起那本书，却发现你看花了眼，其实那里什么都没有。\n");
		}
		obj->move(me);
		message_vision("$N从石匣中取出一本书。\n",me );
message("channel:rumor", MAG"【谣言】某人："+this_player()->query("name")+"拿到九阴真经上卷啦。\n"NOR, users());
	}
	else
		return notify_fail("你要拿起那本书，却发现你看花了眼，其实那里什么都没有。\n");
	return 1;
}

