//Room: gudelin2.c 古德林
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_shibei();

void create()
{
      set("short","古德林");
      set("long",@LONG
这是一片密密的楠木林，株株秀挺俊拔，枝叶分披上捧，如两手拥佛，据
说有七万株之多，要是不熟悉地形很容易迷路。林中有一片空地，几只楠木桩
排成梅花模样。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south"     : __DIR__"bailongdong",
          "southeast" : __DIR__"gudelin3",
          "southwest" : __DIR__"gudelin1",
          "northeast" : __DIR__"gudelin1",
          "northwest" : __DIR__"gudelin1",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6140);
	set("coor/y", -1070);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}