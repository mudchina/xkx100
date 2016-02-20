//Room: hcaxiuxishi.c 华藏庵休息室
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","华藏庵休息室");
      set("long",@LONG
这里是峨嵋华藏庵的休息室。窗帘拉下来，房里整整齐齐放了很多木床。
有几个夜晚守庵的小师太正在睡觉。
　　休息室外就是禅房。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north" : __DIR__"hcachanfang", 
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
	set("coor/x", -6210);
	set("coor/y", -1200);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}
