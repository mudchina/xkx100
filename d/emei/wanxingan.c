//Room: wanxingan.c 万行庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","万行庵");
      set("long",@LONG
太子坪万行庵是古智禅师创建的。庵外满山长满莎椤花，花数芭合成一朵，
叶子包在花外，古人以其根坚难易而盛赞之，以喻洁身自好之高贵品质。由此
向南上便至金顶，下至接引殿。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/jia" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"jieyindian",
          "southup"   : __DIR__"jinding",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1130);
	set("coor/z", 180);
	setup();
      replace_program(ROOM);
}