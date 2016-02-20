//Room: caopeng.c 草棚
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","草棚");
      set("long",@LONG
这是峨嵋山脚下一个简单的草棚，地上堆着些上货。很多上山的游客都在
这里买些上山用品。草棚后有个口井，西面是一间马厩。
LONG);
      set("outdoors", "emei");
      set("objects", ([
               __DIR__"npc/xiao-fan": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "west"      : __DIR__"majiu1",
          "east"      : __DIR__"qsjie2",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6020);
	set("coor/y", -1020);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}