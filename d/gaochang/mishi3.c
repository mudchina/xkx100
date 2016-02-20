// room: well1.c
// Jay 4/8/96

inherit ROOM;
#include <ansi.h>
#define BOOK "/clone/book/lbook9"
int do_use(string arg);
int do_zuan(string arg);


void create()
{
        set("short", "暗室");
        set("long", @LONG
这是在高昌最深处的一个暗室，什么也看不清。
LONG );
        set("exits", ([
                "out" : __DIR__"mishi2",
        ]));
        set("no_clean_up", 0);
		set("item_desc", ([
				"hole" : "一个不知深浅的石洞，不知该不该搜一搜看。\n"
        ]));
        set("count",1);
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_search", "search");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             message_vision("$N点燃了火折，发现墙壁上有一小洞(hole)，似乎有什么东西在里面。\n",me);
         me->set_temp("marks/fire", 1);
         return 1;
       }
}

int do_search(string arg)
{
      object me,ob;
      object book;
      object none;
      me = this_player();
      

			if (!me->query_temp("marks/fire"))
			return 0;
			if (!arg || (arg!="hole" && arg!="小洞"))
			return notify_fail("你要搜哪里？\n");
			if (query("count")<1)
				{
					return notify_fail("洞里面什么也没有了。\n");
					}
			if (me->query("cor")<25)
					return notify_fail("你刚想伸手，忽然有点害怕，想了想还是算了。\n");
			add("count",-1);
      book=new(BOOK);
      if (book->violate_unique())
        {
        	destruct(book);
        	book=none;
        }
			if (random(4)>0 && book)
				{
					message_vision("$N往洞里摸了摸，摸出一本古书来。\n",me);
 					message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"拿到一本"+book->query("name")+"啦。\n"NOR, users());
					book->move(me);
				}
			else if(random(4)>1)
				{
					ob=new("clone/money/gold");
					ob->set_amount(random(30));
					message_vision("$N往洞里摸了摸，摸出了一些黄金。\n",me);
					ob->move(me);
					}
			else 
				{
					ob=new("clone/money/silver");
					ob->set_amount(random(30));
					message_vision("$N往洞里摸了摸，摸出了一些白银。\n",me);
					ob->move(me);
					}
			
      return 1;
}

