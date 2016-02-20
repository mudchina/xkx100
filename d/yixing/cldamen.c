// /d/yixing/cldamen.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;
#include <ansi.h>

void create()
{
  set("short", "大门");
  set("long", @LONG
这里便是威镇江南的长乐帮总舵所在。那长乐帮在江湖上声势非同
小可，近年来更是日渐兴旺。两扇红漆大门上钉着狰狞的虎头，几个满
脸横肉的帮众站在两侧。门上有一个大匾(bian)，两盏气死风灯来回摇
摆。旁边有一座碑(bei) ，上面刻着一些文字。
LONG );

  set("exits", ([
    "enter" : __DIR__"cldating",
    "south" : __DIR__"shulin4",
  ]));

  set("item_desc",([
    "bian" : 
"    ※※※※※※※※※※※※※※※※※※※\n"
"    ※※※※　　　　　　　　　　　※※※※\n"
"    ※※※※　　长　　乐　　帮　　※※※※\n"
"    ※※※※　　　　　　　　　　　※※※※\n"
"    ※※※※※※※※※※※※※※※※※※※\n",
      "bei" :
"    长乐，据传出自唐李颀诗：“莫是长安行乐处，空令岁月易蹉跎。”\n"
"    长乐帮原是江湖上不入流的小帮，从第七代帮主时，开始声名鹊起。\n"
"    帮中自帮主、总管以下，分为龙灵堂，狮敏堂，熊威堂，虎猛堂和豹\n"
"    捷堂，其分舵更是遍布各地，好手如云。长乐帮行事亦正亦邪，阴魂\n"
"    不散，黑白两道人物无不避让三分。正如市井小儿歌谣云：长乐无常，\n"
"    无常长乐。\n",
  ]));

  set("objects",([
    __DIR__"npc/cl_qiu" : 1,
  ]));
  set("outdoors", "yixing");

  setup();
}

int valid_leave(object me, string dir)
{
  object ob;

  me = this_player();
  if( dir == "enter" &&
      objectp(ob = present("qiu shanfeng", environment(me))) &&
      living(ob) &&
       me->query("family/family_name") != HIC"长乐帮"NOR &&
      !me->query_temp("changle"))
    return notify_fail("邱山风拦在你面前，说道：你他妈的怎么连一点江湖规矩都不懂？起码也得孝敬一下老子。\n");
  else
    {
//      me->delete_temp("changle");
      return ::valid_leave(me, dir);
   }
}