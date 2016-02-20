// caochang.c 草场
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "草场");
        set("long", @LONG
这一族哈萨克人大概已经习惯了定居生活，于是做了个大草场。春夏
把远处肥嫩的水草割下来堆在这里，以备秋冬季节畜生的食料。这里堆满
了一堆堆帐篷大小的草堆和干草(gancao)，看起来不下千堆。
LONG);
        set("exits", ([
            "northdown" : __DIR__"pmchang",
            "westdown" : __DIR__"shuijing",            
            "east" : __DIR__"caoyuan1",
        ]));
        set("objects", ([
                    __DIR__"npc/hasake" : 1
        ]));
        set("item_desc", ([
                "gancao" : "  这是堆积在草场理的草堆，地上还零零散散地放了
好多已经晒干的水草。你可以帮助牧民们把干草堆(dui)成堆。\n",
        ])); 
        set("outdoors", "hasake");
        setup();
}

void init()
{
        add_action("do_dui", "dui");
}

int do_dui(string arg)
{      
        object me, weapon;
        int costj, costq;
        string skill;
        me = this_player();
        weapon = me->query_temp("weapon");
        if(!living(me)) return notify_fail("你发疯了? \n");
        if(!weapon) return notify_fail("你用手来堆？有性格！\n");
        if(!arg || arg != "gancao"){    
              message_vision("$N拿起$n在地上磨了磨。\n",me, weapon);
              return 1;
              }        
        costj = 1500 / (int)me->query("con");
        costj = random(costj);
        costq = 2000 / (int)me->query("str");
        costq = random(costq);

        if((int)me->query("jing") < costj || (int)me->query("qi") < costq){
               message_vision(HIR "\n 啊！。。。\n由于$N用力过猛，一大堆干草倒下来压在了$N身上！\n"NOR,me);
               me->unconcious();
               return 1;
               }        
        me->add("jing", -costj);
        me->add("qi", -costq);       
        message_vision("$N用$n拉起一把干草堆在草堆上。\n", me, weapon);
        skill = weapon->query("skill_type");
        if(me->query_skill(skill, 1) < 120){
                write(HIY "你使劲地叉着干草，只觉得手中这"+weapon->name()+HIY"是越来越好用。\n"NOR);
                me->improve_skill(skill, (int)(me->query_int()/3));
                }
        else write("你使劲地叉着干草，但却发现没有什么好玩的。\n");
        return 1;
}
