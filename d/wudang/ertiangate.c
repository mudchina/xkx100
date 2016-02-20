//Room: ertiangate.c 二天门
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","二天门");
      set("long",@LONG
这里是“二天门”，金光灿灿的金顶就在眼前了。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"toutiangate",
          "southup"  : __DIR__"santiangate",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -1020);
	set("coor/z", 160);
	setup();
      replace_program(ROOM);
}