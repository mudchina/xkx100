//Room: sanlaofeng.c 三老峰
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","三老峰");
      set("long",@LONG
只见三座奇峰突兀，惊险无比，行人多不敢放胆在此玩赏风景。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"wuyaling",
          "southup"  : __DIR__"wulaofeng",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -960);
	set("coor/z", 120);
	setup();
      replace_program(ROOM);
}