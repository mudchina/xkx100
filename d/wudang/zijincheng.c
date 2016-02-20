//Room: zijincheng.c 紫金城
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","紫金城");
      set("long",@LONG
这是守护金殿的紫金城墙，周长三里，城墙由花岗石依山势砌成，
东西北城门均面临绝壁，南门为上下路口，气势壮观。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"     : __DIR__"jinding",
          "south"     : __DIR__"jindian",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -1050);
	set("coor/z", 180);
	setup();
      replace_program(ROOM);
}
