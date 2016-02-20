//entrance of gaochang.
//bye yuan
#include <ansi.h>

inherit ROOM;
   

void create ()
{
  set ("short", "高昌大门");
  set ("long", @LONG
    转过了一排树木，只见一座石山上嵌著两扇铁铸的大门,
  大门看样子重逾千钧，据说是古代高昌国王为了抵御强敌而设计的。
  门上铁锈斑驳，显是历时已久的旧物。但是门上的门环(huan)
  似乎可以扭(niu).门上写着：
               ****************
               *              *
               *  高 昌 大 殿 *
               *              *
               ****************

LONG);

  set("outdoors", "gaochang");
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie3",
]));

  setup();
}

void init()
{
   add_action("do_niu", "niu");
}



void check_trigger()
{
   object room;
   object me=this_player();
   int exp,pot,score;
if( (int)query("left_trigger")==2

   &&   (int)query("right_trigger")==5
   &&   !query("exits/down") ) {
     message("vision", "铁门忽然发出轧轧的声音，露出一个向下的阶梯。\n", this_object() );
      if( !(room = find_object(__DIR__"dadian")) )
              room = load_object(__DIR__"dadian");

     if( room = find_object(__DIR__"dadian") ) {
           set("exits/down", __DIR__"dadian");
           room->set("exits/up", __FILE__);
        
          message("vision", "铁门忽然发出轧轧的声音，露出一个向上的阶梯。\n",room );
	        if (!me->query("skybook/baima/damen"))
          {
         	 me->set("skybook/baima/damen",1);
  	       exp=500+random(1000);
           pot=exp/2;
           score=pot/2;
           me->add("combat_exp",exp);
           me->add("potential",pot);
           tell_object(me,HIC"你成功打开了通往高昌大殿的铁门！\n在这次历练中你获得了"+
           	         chinese_number(exp)+"点经验、"+
                     chinese_number(pot)+"点潜能以及"+
                     chinese_number(score)+"点江湖阅历。\n\n"NOR);
          }
     }
     delete("left_trigger");
     delete("right_trigger");
     call_out("close_passage", 10);
   }
}

void close_passage()
{
   object room;

   if( !query("exits/down") ) return;
   message("vision", "铁门忽然发出轧轧的声音，将向下的通道盖住了。\n",
     this_object() );
   if( room = find_object(__DIR__"dadian") ) {
     room->delete("exits/up");
     message("vision", "铁门忽然发出轧轧的声音，向上的通道又缓缓地被盖住了。\n",
        room );
   }
   delete("exits/down");
   delete("left_trigger");
   delete("right_trigger");
}


int do_niu(string arg)
{
   string dir;
   object me=this_player();

   if( !arg || arg=="" ) return 0;

   if( arg=="huan" ) {
     write("你试着扭动门环，似乎可以左右滑动....\n");
delete("left_trigger");
delete("right_trigger");
     return 1;
   }
   if( sscanf(arg, "huan %s", dir)==1 ) {
     if( dir=="right" ) {
if(query("exits/down")) return notify_fail("铁门已经被扭开了。\n");
        message_vision("$N将门环往右扭...，忽然「喀」一声铁门又移回原位。\n", me);
        add("right_trigger", 1);
        check_trigger();
        return 1;
     } else if( dir=="left" ) {
if(query("exits/down")) return notify_fail("铁门已经被扭开了。\n");
        message_vision("$N将门环往左扭...，忽然「喀」一声铁门又移回原位。\n", me);
        add("left_trigger", 1);
        check_trigger();
        return 1;
     } else {
        write("你要将门环往哪边扭？\n");
        return 1;
     }
   }
}


void reset()
{
   ::reset();
   delete("left_trigger");
   delete("right_trigger");
}
int valid_leave(object me, string dir)
{
 if(dir=="d" || dir=="down")
{
if(this_player()->query("combat_exp")<100000)
{
  return notify_fail("一股恐怖的氛围从脚底心升起，使你两腿颤抖不止，无法举步。\n");
}

}
return ::valid_leave(me,dir);
}
