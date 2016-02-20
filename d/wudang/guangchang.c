//Room: guangchang.c 武当广场
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","武当广场");
      set("long",@LONG
这是一个由大石板铺成的广场，是武当弟子学习武功和互相切磋的
地点。周围种满了梧桐树，一到秋天就是满地的落叶。一个年纪轻轻的
道童正在打扫。南边是灵霄宫三清殿。
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/daotong": 2,
           CLASS_D("wudang") +"/first": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"zixiaogate",
          "south"      : __DIR__"sanqingdian",
          "eastdown"   : __DIR__"tyroad1",
          "east"       : __DIR__"shanlu2",
      ]));
//      set("no_clean_up", 0);
      set("outdoors", "wudang");
	set("coor/x", -2050);
	set("coor/y", -910);
	set("coor/z", 90);
	setup();
      replace_program(ROOM);
}
