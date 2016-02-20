//Room: songlin2.c 松林 
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","山谷");
      set("long",@LONG
你沿着雕鸣声走入深谷，景致更加秀丽了。你侧耳倾听，
雕鸣声似乎就在耳边，你不禁加快了脚步。
LONG);
      set("outdoors", "jianzhong");
      set("exits",([ /* sizeof() == 1 */
          "west"  : __DIR__"shulin13",
	  "east"   : __DIR__"shulin13",
	  "north"   : __DIR__"dongkou",
          "south"  : __DIR__"shulin4", 
      ]));
	set("coor/x", -400);
	set("coor/y", -450);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}