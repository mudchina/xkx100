// Room: /d/city/jiaowai2.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;
#define MAX_EXP 2000

void create()
{
	set("short", "树林");
	set("long", @LONG
扬州郊外的树林，松枝挺拔，乔木横斜。林间小道，逶迤随远。林
中蝉鸣厮闹，鸟啼宛转，使你顿时烦意尽消。无数的小鸟小雀在树
梢上欢歌，一点也不怕人。这正是个打鸟（da）的好机会。
    地上落了很多树枝石块。
LONG );
	set("exits", ([
		"north" : __DIR__"jiaowai1",
		"south" : __DIR__"jiaowai3",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/qiu-wanjia": 1,
		__DIR__"obj/shuzhi": 1,
		__DIR__"obj/shitou": 1,
	]));
	set("outdoors", "yangzhoue");
	set("coor/x", 70);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();	
}

void init()
{
        add_action("do_da", "da");
}


int do_da()
{
        object me;
        int i, kar, cps, add_exp, add_pot, add_score;
        me = this_player();

        if (me->query("combat_exp")>=MAX_EXP)
            return notify_fail("这样的游戏还是让小孩们玩吧！\n");
        
        if(me->is_busy())
             return notify_fail("你还是等弓装好了箭再打鸟吧！\n");

        if(me->query("qi")<10)
             return notify_fail(HIR"你太累了，还是先休息一下吧，射箭也要用力气哟。。\n"NOR);
             

        me->start_busy(3);
        message_vision("$N拿起儿时玩耍用的小弓小箭，瞄准树上的小雀射去......\n", me);
        message_vision("$N只听树上一阵鸟儿急鸣…\n",me);
        kar = random((int)me->query("kar"));
        
        if (kar<=5) 
           {
           	message_vision("$N什么也没打到。\n",me ); 
           	          	           	          
            }
        else 
        
           {    
                if (kar>5 && kar<=8) 
                   
                   {
                      message_vision("$N打到一只"YEL"麻雀。\n"NOR, me);
                      add_exp=4+random(5);
                      add_pot=4+random(5);  
                   }
                 if (kar>8 && kar<=10) 

                    {
                      message_vision("$N打到一只"HIG"鹦鹉。\n"NOR, me);
                      add_exp=6+random(5);
                      add_pot=6+random(5);                 
                     }  
                 if (kar>10 && kar<=15)
                
                   {
                      message_vision("$N打到一只"HIY"金丝雀。\n"NOR, me);                    
                      add_exp=8+random(5);
                      add_pot=8+random(5);   
                    }       
                if (kar >15) 
                
                   {
                      message_vision("$N打到一只"HIW"百灵鸟。\n"NOR, me);                    
                      add_exp=10+random(5);
                      add_pot=10+random(5);                                                                                                                              
                    }        
                    
                add_score=10+random(5);                               
                
                me->add("combat_exp",add_exp);
                me->add("potential",add_pot);
                me->add("score",add_score);
                tell_object(me,HIW"你得到了:"
                            + chinese_number(add_exp) + "点实战经验，"
                            + chinese_number(add_pot) + "点潜能，"
                            + chinese_number(add_score) + "点江湖阅历。\n"NOR);

             }                   
         me->receive_damage("qi", 5);
         return 1;      
 }
       