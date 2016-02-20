// 绿洲

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "回疆绿洲" NOR);
        set("long", @LONG
在戈壁的尽头出现了一个绿洲。这里有口水井，可是已经干涸了。
LONG);
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("objects", ([
                    __DIR__"obj/hamigua" : 2

        ]));
 
        set("exits", ([
              "northwest" : __DIR__"gebi1",
              "southeast" : __DIR__"gebi2",
              "southwest" : __DIR__"gebi3",
              "northeast" : __DIR__"gebi4",
        ]));

        set("outdoors", "hasake");
        set("no_quest",1);
        setup(); 

}

void init()
{
       object me = this_player();
      if(objectp(present("shou juan", me))){
       switch(random(4)) {
       case 0 :
               me->set_temp("gc1_n",1); 
               tell_object(me, HIC "突然从手绢上显出一条指向北面的细线来。\n" NOR);          
               break;
       case 1 :
               me->set_temp("gc1_s",1); 
               tell_object(me, HIC "突然从手绢上显出一条指向南面的细线来。\n" NOR);
               break;
       case 2 :
               me->set_temp("gc1_e",1); 
               tell_object(me, HIC "突然从手绢上显出一条指向东面的细线来。\n" NOR);
               break;
       case 3 :
               me->set_temp("gc1_w",1); 
               tell_object(me, HIC "突然从手绢上显出一条指向西面的细线来。\n" NOR);
               break;
       }
    }             
}