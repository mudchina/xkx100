//Room: shizhu.c 石柱
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","石柱");
      set("long",@LONG
这是南岩宫前的一根石柱，雕成龙形，自峭壁上横出，犹如飞龙在
天。龙首刻一香炉，在此上香称为“上龙头香”，是香客的最大心愿。
石柱仅粗如屋梁，旁无扶栏，前有白云缭绕，下有万丈深渊，稍一失足，
即尸骨无存。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northup"  : __DIR__"nanyanfeng",
          "enter"    : __DIR__"nanyangong",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -950);
	set("coor/z", 100);
	setup();
}

void init()
{
        add_action("do_mianbi", "face");
}


int do_mianbi(string arg)
{
   object ob;

   ob = this_player();
   if ( !arg )
   {
      message_vision("$N面对着石柱趺坐静思良久，白忙一场，一无所获。\n",ob);
      return 1;
   }
   if ((int)ob->query_skill("taoism", 1) <100)
   {
      message_vision("$N面对着石柱上满面蝌蚪文，没一个字认识。\n",ob);
      return 1;
   }
   if ((int)ob->query_skill("literate", 1) <100)
   {
      message_vision("$N对石柱上每一个字都认识，就是不知道说的是什么。\n",ob);
      return 1;
   }
   if (((int)ob->query_skill("huagong-dafa", 1) >0)||
       ((int)ob->query_skill("huntian-qigong", 1) >0)||
       ((int)ob->query_skill("hunyuan-yiqi", 1) >0)||
       ((int)ob->query_skill("linji-zhuang", 1) >0)||
       ((int)ob->query_skill("xuantian-force", 1) >0)||
       ((int)ob->query_skill("zixia-shengong", 1) >0))
   {
      message_vision("$N旁门杂学太多了，实在静不下心来面壁。\n",ob);
      return 1;
   }    
   if (
      arg == "liangyi-jian" ||
      arg == "tiyunzong")
   {
      if ((int)ob->query_skill(arg, 1) <100)
      {
         message_vision("$N的" + to_chinese(arg) + "显然太低，无法领悟石柱内容。\n",ob);
         return 1;
      }
      if ((int)ob->query_skill(arg, 1) > 180)
      {
         message_vision("$N的" + to_chinese(arg) + "已经没必要读石柱内容了。\n",
ob);
         return 1;
      }
      if(((ob->query_skill(arg,1)
        *ob->query_skill(arg,1)
        *ob->query_skill(arg,1)/10)> (int)ob->query("combat_exp"))
        && arg != "literate")
      {
         message_vision("$N的实战经验不足，无法领悟石柱内容。\n",ob);
         return 1;
      }
      if (ob->query("jing")<20)
      {
         message_vision("$N太累了，现在无法领悟石柱内容。\n",ob);
         return 1;
      }
      message_vision("$N面对着石柱趺坐静思，良久，对" + to_chinese(arg) + "似有所悟。\n",ob);
      ob->improve_skill(arg, random(10*ob->query("int")));
      ob->add("jing",-5);
      return 1;
   }
   message_vision("$N面对着石柱趺坐静思，良久，似有所悟。\n",ob);
   ob->add("jing",-5);
   return 1;
}
