//Room: toutiangate.c 头天门
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","头天门");
      set("long",@LONG
只见有石梯无数通往山巅，一座石坊上写着“头天门”三个大字，
这是攀登武当绝顶天柱峰的起点。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"huixianqiao",
          "southup"  : __DIR__"ertiangate",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -1010);
	set("coor/z", 150);
	setup();
      replace_program(ROOM);
}
