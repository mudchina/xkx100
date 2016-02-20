// Room: /d/xiakedao/road8.c


#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "一线天");
        set("long", @LONG
这里便是一线天。此处山势甚是陡峭，两旁都是无底的深渊，
中间是一条近似九十度的坡形山路。行人到此无不心惊胆颤，只盯
着自己的脚，生怕一不小心掉下深渊。
LONG );
        set("exits", ([
                "southup"   : __DIR__"wangyun",
                "northdown" : __DIR__"road7",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xiakedao");
	set("coor/x", -3110);
	set("coor/y", -22140);
	set("coor/z", 30);
	setup();
}

void init()
{
        object me = this_player();

        if( random((int)me->query_skill("dodge",1))<= 30)
        {
                me->receive_damage("qi", 50);
                me->receive_wound("qi",  50);
                message_vision(HIR"$N一不小心脚下踏了个空，... 啊...!\n"NOR, me);
                me->move(__DIR__"road5");
                tell_object(me, HIR"你从山上滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
                message("vision", HIR"只见" + me->query("name") + "从山上骨碌碌地滚了下来，躺在地上半天爬不起来!\n"NOR, environment(me), me);
        }
}