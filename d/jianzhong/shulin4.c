//Room: songlin2.c 松林 
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","山谷");
      set("long",@LONG
顺着小溪，你不知不觉中来到了一个幽静的山谷，
绿树成荫，山花灿烂。只是北方隐隐传来几声雄
壮悲呛的雕鸣，打破了四周的寂静。
LONG);
      set("outdoors", "jianzhong");
      set("exits",([ /* sizeof() == 1 */
          "west"  : __DIR__"shulin14",
	  "east"   : __DIR__"shulin14",
	  "north"   : __DIR__"shangu",
          "south"  : __DIR__"shulin3", 
      ]));
	set("coor/x", -400);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}