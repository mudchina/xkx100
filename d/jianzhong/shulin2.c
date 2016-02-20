//Room: songlin2.c 松林 
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","树林");
      set("long",@LONG
这是树林深处，暗无天日，朦胧中只感觉到左右前后到处
都是树影。一条小溪蜿蜒蛇行，静静地流淌着。
LONG);
      set("outdoors", "jianzhong");
      set("exits",([ /* sizeof() == 1 */
          "north"  : __DIR__"shulin13",
	  "east"   : __DIR__"shulin3",
	  "west"   : __DIR__"shulin2",
          "south"  : __DIR__"shulin1", 
      ]));
	set("coor/x", -400);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}