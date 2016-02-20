//Room: chuwujian.c 储物间
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","储物间");
      set("long",@LONG
这里便是峨嵋华藏庵的储物间，四周都是架子。一个架上放满了各样兵
器，有长剑，拂尘，长鞭等，琳琅满目。另一个架上放了各种防具。还有一
个架上摆了许多小柜子，原来是装满药品的药柜。一位师太负责管理这里的
物品，正忙碌着整理防具。后面好象有个小楼梯。门外就是斋堂了。
LONG);
      set("objects",([
           CLASS_D("emei") + "/feng" : 1,
           __DIR__"obj/fuchen" : 1,
           __DIR__"obj/zhujian" : 1,
           __DIR__"obj/jiudai" : 1,
           __DIR__"obj/yaodai" : 1,
//  软剑(Ruanjian)
      ]));
      set("exits",([ /* sizeof() == 1 */
          "up"    : __DIR__"cangjingge", 
          "north" : __DIR__"hcazhaitang", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6190);
	set("coor/y", -1200);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}