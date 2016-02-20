// chufang.c 厨房
// Winder Oct.10 1998

inherit ROOM;
int do_kan(string arg);

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是全真教的厨房，屋角上堆着一大堆手臂粗细的木柴，看
来还没有劈好。一位火工道人正愁眉苦脸地坐在那里，看着那堆柴。
墙上挂着一块牌子(paizi)，墙边扔着一把柴刀。
LONG
        );
        set("exits",([
                "west" : __DIR__"shantang",
        ]));
        set("item_desc", ([
            "paizi": "招收砍柴工人，待遇从优。\n"
        ]) );
        set_temp("times" , 20);
        set("objects" , ([
                __DIR__"npc/huogong" : 1,
        ]));

	set("coor/x", -2730);
	set("coor/y", 80);
	set("coor/z", 170);
	setup();
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object me=this_player();
        object ob;
        if (query_temp("times")==0)
                return notify_fail("今天的活干完了，明天再来吧！\n");

        if (!arg || arg != "柴")
                return notify_fail("别乱砍，小心伤着自个儿。\n");

        if(present("huogong", environment(me)) && living(present("huogong", environment(me))))
        {
        if ( (int)me->query("jing")<50)
                return notify_fail("你的精力不够了，休息一会儿再砍吧。\n");

        message_vision("$N拣起柴刀，竖起一根柴火，奋力砍下去。\n",me);
	add_temp("times",-1);

        if (random(3)<2) {
                me->receive_damage("jing",20+random(20));
                message_vision("结果$N用力过猛，柴刀一下子嵌在了柴里。$N用尽吃奶
的力气把柴刀拔出来，又摔了个大跟斗。\n",me);
        }
        else {
                me->receive_damage("jing",20+random(40));
                ob = new("/clone/money/silver");
                ob->set_amount(10);
                ob->move(me);
                message_vision("结果木柴应声被劈成两半。火工道人笑着对$N说，你工
作的不错呀，这是你的酬劳。\n",me);
                message_vision("火工道人给$N一些银子。\n",me);
        }
        return 1;
        }
        else
                return notify_fail("老板都不见了，你为谁白干啊？\n");
}