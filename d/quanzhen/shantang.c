// shantang.c
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "膳堂");
        set("long", @LONG
这里是全真教的膳堂，是弟子们用餐的地方。这个堂很大，
整齐地摆放着一排一排的桌椅。现在桌椅上三三两两地坐着全真
弟子，有的正在用餐，有的低头谈笑。看着可口的饭菜，你忍不
住也想叫(order)一份。
LONG
        );
        set("exits",([
                "north" : __DIR__"xiuxishi",
                "east" : __DIR__"chufang",
                "northwest" : __DIR__"wuchang2",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2740);
	set("coor/y", 80);
	set("coor/z", 170);
	setup();
}

void init()
{
        add_action("do_order","order");
}

int do_order(string arg)
{
        object me=this_player();
        object food;
        object water;

        if (arg)  return notify_fail("这样东西这里没有啊。\n");
        if (me->query("family/family_name") != "全真教")
        {
              message_vision("火工道人冲出来，瞪了$N一眼：“你哪里来的！敢来混饭吃！”\n",me);
              return 1;
        }

        if ((present("bowl",this_player()) || present("rice",this_player())))
              message_vision("火工道人冲出来，瞪了$N一眼：“还没吃完又想要！”\n",me);
        else
        {
              message_vision("火工道人连忙从厨房出来，把一碗米饭和一碗水拿了给$N。\n",me);
              food=new(__DIR__"obj/rice");
              water=new(__DIR__"obj/bowl");
              food->move(me);
              water->move(me);
        }
        return 1;
}

int valid_leave(object me,string dir)
{
        me=this_player();
        if(( dir=="north" || dir=="northwest")
        && (present("bowl",this_player()) || present("rice",this_player())))
             return notify_fail("火工道人说道：食物和饮水不能带出膳堂去。\n");
        return ::valid_leave(me,dir);
}