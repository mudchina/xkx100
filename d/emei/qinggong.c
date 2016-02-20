//Room: qinggong.c 峨嵋寝宫
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","峨嵋寝宫");
      set("long",@LONG
这是峨嵋山金顶华藏庵外的一片小树林峨嵋寝宫。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/zhou" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"xiaoshulin4", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1200);
	set("coor/z", 180);
	setup();
      replace_program(ROOM);
}