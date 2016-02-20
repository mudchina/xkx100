//Room: santiangate.c 三天门
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","三天门");
      set("long",@LONG
这里是登山石阶的尽头“三天门”，再往上走就是武当绝顶了。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"ertiangate",
          "southup"  : __DIR__"jinding",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -1030);
	set("coor/z", 170);
	setup();
      replace_program(ROOM);
}