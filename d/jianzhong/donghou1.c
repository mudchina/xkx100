#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","谷后树林");
	set("long",@LONG
树林里郁郁葱葱，鸟语花香，光线从树叶的缝隙中洒
向大地，微风吹来，树影一阵婆娑。四周全是树，一片绿
色，在碧绿的海洋中，你渐渐地迷失了方向。
LONG
	);
	set("exits",([
		"east":__FILE__,
		"west":__FILE__,
		"north":__FILE__,
		"south":__FILE__,
	]));
	set("snake_count",5);
	set("outdoors", "jianzhong");
	set("coor/x", -400);
	set("coor/y", -420);
	set("coor/z", 0);
	setup();
}
void init()
{
	object ob1,ob2;
	object me=this_player();
	if((random(10)<2)&&(this_object()->query("snake_count")>0)&&(me->query_temp("dugu_visit")!=0)&&(!present("pusi qushe", environment(this_player()))))
	{	
		ob1=new(__DIR__"npc/pusiqushe");
		ob1->move(this_object());
		this_object()->add("snake_count",-1);
	}
}
int valid_leave(object me, string dir)
{
	int i;
	string msg;
	if(!me->query_temp("dugu_visit"))
	{
		if(dir=="north")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i>0)&&(i<10)) me->add_temp("zhongnan/tree",-1);
			if((i>9)&&(i<12)) me->add_temp("zhongnan/tree",1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if(dir=="south")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i<4)||(i==14)) 
			{	me->add_temp("zhongnan/tree",1);} else me->add_temp("zhongnan/tree",-1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if(dir=="east")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i>3)&&(i<10))
			{	me->add_temp("zhongnan/tree",1);} else me->add_temp("zhongnan/tree",-1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if(dir=="west")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i>11)&&(i<14))
				me->add_temp("zhongnan/tree",1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if (me->query_temp("zhongnan/tree") >= 15)
         	{
     	    		me->move(__DIR__"donghou");
           		me->delete_temp("zhongnan/tree");
			message("vision",me->query("name")+"一脸倦容地从树林中钻了出来。\n",environment(me),me);
             		return notify_fail("你走了半天，终于走出了这片树林。\n");
         	} else
		if (me->query_temp("zhongnan/tree") < i)
		{
			message("vision",me->query("name")+"胡乱地在树林中钻来钻去。\n",environment(me),me);
			msg="你走了几步，发现你走进了树林的更深处。\n";
		} else
		if (me->query_temp("zhongnan/tree") == i)
		{
			message("vision",me->query("name")+"钻进了树林，可是一会儿又走回了原地。\n",environment(me),me);
			msg="你钻进了树林，可是一会儿又走回了原地。\n";
		} else
		{
			message("vision",me->query("name")+"似乎胸有成竹地钻进了树林里。\n",environment(me),me);
			msg="你走了几步，发现这儿你似乎曾经走过。\n";
		}
		return notify_fail(msg);//::valid_leave(me,dir);
	}else 
	if (me->query_temp("dugu_visit")==1)
	{	if(dir=="north")
		{
			message("vision",me->query("name")+"向树林深处走去，消失树林之中……\n",environment(me),me);
			me->move(__DIR__"qiaobi");
			me->delete_temp("dugu_visit");
			message("vision",me->query("name")+"从树林中走了过来。\n",environment(me),me);
			return notify_fail("你往北走了里许，来到了一座峭壁之前。\n");
		} else
		{
			message_vision("$N在树林里信步而行，边走边欣赏风景。\n",me);
			return ::valid_leave(me,dir);
		}
	}
}