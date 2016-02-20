// table.c
inherit ITEM;

void init()
{
  add_action("do_climb", "climb");
  add_action("do_climb", "pa");
  add_action("do_move", "move");
  add_action("do_move", "yi");
}

void create()
{
        set_name("供桌", ({"table", "gongzhuo"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", "这是一张楠木供桌，桌上有一盏油灯。\n");
               set("unit", "张");
               set("material", "wood");
               set("no_get", "\n你拿不动.\n");
        }
        setup();
}

int do_climb(string arg)
{
        object me = this_player();
        int i;
	if (!id(arg)||arg!="table")
                return notify_fail("你要往哪儿爬？\n");
        if (this_player()->query_temp("marks/爬") ) {
                       write("你怎么爬个没完没了？\n");
                        return 1;
        }
        else {
               message_vision("$N爬上供桌。\n",this_player());         
		if (random(5) != 0)
		{
                this_player()->set_temp("marks/爬", 1);
		return 1;
		}
		else
		{
		message_vision("\n$N苯手苯脚地爬上供桌，一不小心把油灯弄倒了！。\n", this_player());
		message_vision("供桌立刻着了火，$N身上带着火就慌慌张张跳了下来。\n", this_player());
		i = (int)me->query_skill("dodge", 1) + random(50);
		if(i<50) { me->die(); return 1;}
		if(i<75) { me->unconcious(); return 1;}
		me->receive_damage("jing", 50 );
		me->receive_damage("qi", 50);
		return 1;
		}	
              }
}

int do_move(string arg)
{
        object ob,me = this_player();
        int i;
	if (!id(arg)||arg!="table")
                return notify_fail("你要移什么？\n");
	if (!(ob = present("jin", this_player())))
	return notify_fail("你没事儿乱移什么？\n");
	if (this_player()->query_temp("marks/移") ) {
        message_vision("$N又把供桌移了回去。\n",me);
	this_player()->delete_temp("marks/移");
        }
        else {
        message_vision("$N把供桌移开。\n",me);
       this_player()->set_temp("marks/移",1);
	     }
return 1;
}
