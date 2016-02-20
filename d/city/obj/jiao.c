// Room: /city/jiao.c
// Date: Feb.14 1998 by Java
inherit ITEM;
#include <ansi.h>
void setup()
{}
void init()
{
        add_action("do_enter", "enter");
}
void create()
{
        set_name(CYN"蓝呢官轿"NOR, ({"jiao",}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一顶兰呢大官轿，是扬州知府和成都提督共同出资设立的，往返两地的快轿。\n");
                set("unit", "顶");
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_drop", 1);
                set("no_put", 1);
        }
        setup();
}
int do_enter(string arg)
{
	object room, me = this_player();
        if( !arg || arg!="jiao" ) return 0;
        message_vision("$N一哈腰掀开轿帘往轿里钻进去。\n\n", me ) ;
        if( !(room = find_object(__DIR__"jiaonei")) )
            room = load_object(__DIR__"jiaonei");
        if( room = find_object(__DIR__"jiaonei") ) 
	me->move(room);
	message("vision", me->name() + "从轿外钻了进来。\n\n",
		environment(me), ({me}) );
        call_out("reach", 20, me);
	return 1;
}	

void reach(object me)
{
        tell_object(me, "突然，轿子顿了一下停了下来，然后有人说: 到了，落轿。\n");
        me->move("/d/city3/eastroad1");
}
