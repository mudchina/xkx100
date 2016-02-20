//Room: duguangtai.c 睹光台
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","睹光台");
      set("long",@LONG
这里是看日出、云海、佛光、神灯之地。台下深崖万丈，陡彻无底，云遮
雾掩。极目四望，数百里外的大小雪山皆历历在目。
　　金顶云海，迷迷茫茫，笼罩四野，远接天际。云海轻荡时，你在金顶，脚
踏白云，大有飘飘欲仙之感；当云涛迅猛涌来时，整个金顶都似在向前浮动，
令人有乘舟欲风之意。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/bei" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"huacangan",
          "west"     : __DIR__"dgtsheshenya", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1170);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}