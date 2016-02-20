//Room: songlin2.c 松林 
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","树林");
      set("long",@LONG
这是树林深处，暗无天日，朦胧中只感觉到左右前后到处
都是树影。
LONG);
      set("outdoors", "jianzhong");
      set("exits",([ /* sizeof() == 1 */
          "north"  : __DIR__"shulin14",
	  "east"   : __DIR__"shulin13",
	  "west"   : __DIR__"shulin2",
          "south"  : __DIR__"shulin3", 
      ]));
	set("coor/x", -400);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}