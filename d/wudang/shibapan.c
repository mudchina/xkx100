//Room: shibapan.c 十八盘
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","十八盘");
      set("long",@LONG
这是一个很大的斜坡，俗称十八盘，大石阶一级一级笔直而上，颇
费脚力。这里坡坡有神，拐拐有祠，往上十里之后即是灵霄宫。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"shiliang",
          "southup"    : __DIR__"shijie2",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -880);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}
