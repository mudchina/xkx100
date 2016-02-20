//Room: qsjie1.c 青石阶
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","青石阶");
      set("long",@LONG
快到峨嵋山了。这是一条通往峨嵋山的青石阶，两旁绿树荫蔽，空气十分
清新。时常能见到些游人香客。
LONG);
      set("objects", ([
               __DIR__+"npc/youngwoman": 1,
               __DIR__+"npc/puren": 1,
      ]));
      set("outdoors", "sanbuguan");
      set("exits",([ /* sizeof() == 1 */
          "west"       : "/d/chengdu/road1",
          "north"      : __DIR__"xiaolu2",
          "southwest"  : __DIR__"qsjie2",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6000);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}
