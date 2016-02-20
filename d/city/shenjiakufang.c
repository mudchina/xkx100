// Last Modified by Sir 9/15/2001
#include <ansi.h>
inherit ROOM;
int do_yuntang(string arg);

void create ()
{
  set ("short", "沈家库房");
  set ("long", @LONG
你走过一条狭窄的小巷之后来到一间仓库中。这里整齐的堆码着未经
熨烫的布匹和一些成衣。靠墙摆放着几张大桌子，桌子上放着几匹打湿的
布料和一个竖着一个已经烧得发烫的熨斗。你可以在这儿熨烫(yuntang)。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"baiyipu",
]));

  setup();
}
void init()
{
        add_action("do_yuntang","yuntang");
}

int do_yuntang(string arg)
{
        object me=this_player(); 
        object ob;
        if (!me->query_temp("gongzuo/yunbu"))
           return notify_fail("你现在没有熨布的工作。\n");

        if(me->is_busy())
             return notify_fail("你正忙着熨布呢！\n");
             
        if ( (int)me->query("jing")<10)
           return notify_fail("你太累了，休息一下吧。\n");
           
        if ( (int)me->query("qi")<10)
           return notify_fail("你太累了，休息一下吧。\n");   

        if (me->query_temp("gongzuo/yunbu")==6)
           return notify_fail("布料已经熨好了，快把熨好的布交回去吧！\n");
   
  message_vision("$N拿起熨斗慢慢地在布料上来回移动，只见布料上立刻冒出白色的蒸气。\n",me);
        
        if (random(10)>7)
        {
  message_vision(RED"$N在蒸气缭绕之中逐渐开始漫不经心，只听得“哧”的一声$N的手被熨斗碰了一下。\n"NOR,me);     
       me->receive_damage("qi", 10);
         }   
      me->start_busy(2);            
      me->add("jing",-(2+random(5)));
      me->add("qi",-(5+random(5)));
      me->add_temp("gongzuo/yunbu",1);      
  if ( (int)me->query_temp("gongzuo/yunbu")==6)
 {
  message_vision(CYN"布匹在熨烫下逐渐平整，$N将布匹叠好后放在一边。\n"NOR,me);
      me->set_temp("gongzuo/yunbuok",1);
      ob=new("/d/city/obj/bu.c");
      ob->move(me);      
 }
                 
  return 1;
} 
