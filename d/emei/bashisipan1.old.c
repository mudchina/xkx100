//Room: bashisipan1.c 八十四盘
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","八十四盘");
      set("long",@LONG
八十四盘，道路艰险陡峭，迂回盘折，令人不能喘息。路左是蔽日遮天的
冷杉林，路右是深不见底的绝壁峡谷。由此往上至接引殿，北下到洗象池。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"leidongping",
          "southwest"  : __DIR__"bashisipan2",
          "southeast"  : __DIR__"lengsl2",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1110);
	set("coor/z", 160);
	setup();
}
int valid_leave(object me, string dir)
{
      int c_exp,c_skill;
      if (dir == "southwest" )
      {
         c_exp=me->query("combat_exp");
         c_skill=me->query_skill("dodge",1);
         me->add("qi",-10);
         if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
             me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
         tell_object(me,"你爬上八十四盘，有些累了。\n");
      }
      return 1;
}