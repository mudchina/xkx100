//Room: chunyangdian.c 纯阳殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","纯阳殿");
      set("long",@LONG
纯阳殿海拔一千余米，四面古木苍翠，幽静宜人。殿前有一石，叫普贤石，
据说普贤菩萨登山时曾坐在这里休息过。在此可纵观峨嵋诸峰，仰望金顶，悬
崖峭壁，离天咫尺。这里西上至神水庵，东下是归云阁。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"guiyunge",
          "westup"    : __DIR__"shenshuian",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
	set("coor/x", -6090);
	set("coor/y", -1040);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}