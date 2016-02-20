//Room: huacangan.c 华藏庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","华藏庵");
      set("long",@LONG
华藏庵是金顶的主要建筑，规模宏大，中祀普贤菩萨，旁列万佛。
　　华藏庵后边是睹光台，旁边是卧云庵。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "north"      : __DIR__"jinding",
          "northwest"  : __DIR__"woyunan", 
          "south"      : __DIR__"duguangtai",
          "enter"      : __DIR__"hcazhengdian",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1160);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}