// Room: /d/xiakedao/road7.c
  
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "夹鳖石");
        set("long", @LONG
这里便是夹鳖石。此处山势陡峭，行人到此无不心惊胆颤，不
敢大声说话，只求平安过去。登山的人一个不小心，很容易便会跌
堕到崖谷之中。
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup"   : __DIR__"road8",
                "northdown" : __DIR__"road6",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xiakedao");
	set("coor/x", -3110);
	set("coor/y", -22130);
	set("coor/z", 20);
	setup();
}

void init()
{
        object me = this_player();

        if( random((int)me->query_skill("dodge",1)) <= 15)
        {
                me->receive_damage("qi", 50);
                me->receive_wound("qi",  50);
                message_vision(HIR"$N一不小心脚下踏了个空，... 啊...!\n"NOR, me);
                me->move(__DIR__"road3");
                tell_object(me, HIR"你从山上滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
                message("vision", HIR"只见" + me->query("name") + "从山上骨碌碌地滚了下来，躺在地上半天爬不起来!\n"NOR, environment(me), me);
        }
}