//Room: hcadadian.c 华藏庵大雄宝殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","大雄宝殿");
      set("long",@LONG
这是峨嵋山华藏庵的大雄宝殿。正中供奉着普贤菩萨。一群青衣小师太
正在地上诵经。后面有道小门通往后殿。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"hcaguangchang", 
          "south"      : __DIR__"hcahoudian", 
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1180);
	set("coor/z", 200);
	setup();
      replace_program(ROOM);
}