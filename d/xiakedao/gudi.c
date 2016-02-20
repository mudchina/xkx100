// gudi.c 谷底
#include <ansi.h>
inherit ROOM;

int do_climb(string arg);
int do_swim(string arg);
int do_mai(string arg);
void create()
{
        set("short", "谷底");
        set("long", @LONG
这就是悬崖谷底了，三面是高耸的山峰，一面是大海，四周没有
出口，谷底的烟雾很大，走着走着，你隐隐约约见到前面盘膝坐着一
位老者(Oldman)。
LONG );
        set("outdoors", "xiakedao");
        set("item_desc",([
                "feng"     : "看什么呀? 这么高的山你是爬不上去的。\n",
                "shanfeng" : "看什么呀? 这么高的山你是爬不上去的。\n",
                "oldman"   : "你仔细一看，这位老者已经仙去很多年了，留下的只是他的遗骨(gu)，好可怜呀!\n",
                "sea"      : "看什么呀? 你难道想游泳吗? \n",
        ]));
        set("no_clean_up", 0);
        set("coor/x", -4000);
	set("coor/y", -25000);
	set("coor/z", -20);
	setup();
}
void init()
{
        add_action("do_climb","climb");
        add_action("do_mai","bury");
        add_action("do_mai","mai");
        add_action("do_swim","swim");

}
int do_mai(string arg)
{
        int n;

        n = this_player()->query("neili");
        if( !arg || arg != "gu")
        {
                write("什么? \n");
                return 1;
        }
        message_vision("$N找了一块松软的地面，用力挖了起来。\n", this_player());
        if (n > 100)
        {
                message_vision("大约过了半个时辰，$N恭恭敬敬的把老者的遗骨放了进去，埋了起来。突然东面
出现了一个石门。\n", this_player());
                set("exits/east",__DIR__"midao6");
                this_player()->add("neili", -100);
                remove_call_out("close");
                call_out("close",5, this_object());
        }
        else
        {
                message_vision("$N的气力不足，挖了几下就干不动了。\n", this_player());
                this_player()->set("neili",0);
        }
        return 1;
}

void close(object room)
{
        message("vision","石门自动的合上了。\n", room);
        room->delete("exits/east");
}

int do_swim(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="sea")
        {
                write("你想干什么呀?\n");
                return 1;
        }
        message_vision("$N深吸了一口气，跳进海里，奋力的游了起来。\n", me);
        if (random((int)me->query("kar")) > 9)
        {
                message_vision("海上的风浪太大，$N逐渐的失去了知觉。\n", me);
                me->receive_damage("qi", 50);
                me->receive_wound("qi", 50);
                me->move(__DIR__"haitan");
                tell_object(me,HIR"你醒来发现你浑身疼痛，还受了几处伤。\n" NOR);
                message("vision", HIR"只见" + me->query("name") + "被海浪冲到海滩上。\n" NOR, environment(me),me);
        }
        else
        {
                message_vision("海上的风浪太大，$N不得不退了回来。\n", me);
                me->receive_damage("qi",10);
                me->receive_wound("qi",10);
        }
        return 1;
}

int do_climb(string arg)
{
        int n;
        n = this_player()->query_skill("dodge",1);
        if ( !arg || arg!="shan")
        {
                write("你要爬什么呀? \n");
                return 1;
        }
        message_vision("$N深吸了一口气，慢慢的向上爬。\n", this_player());
        if(n >40)
        {
                message_vision("$N爬了半天，突然发现了一个洞口，$N不顾一切钻了进去。\n", this_player());
                this_player()->move(__DIR__"midao8");
        }
        else
        {
                message_vision("$N爬了一会，太累了，不小心滑了下来。\n", this_player());
                this_player()->receive_damage("qi",10);
                this_player()->receive_wound("qi",10);
        }
        return 1;
}
