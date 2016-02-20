//Room: guiyunge.c 归云阁
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","归云阁");
      set("long",@LONG
归云阁，原是唐代福昌达道禅师的道场。宋代绍兴年间，僧人士性又率众
重建。归云阁左有玉女峰，西上可抵纯阳殿，东下是观音堂。
LONG);
      set("objects", ([
           __DIR__"npc/boydizi" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"guanyintang",
          "westup"    : __DIR__"chunyangdian",
          "southup"   : __DIR__"yunufeng",
      ]));
      set("outdoors", "emei");
//      set("no_clean_up", 0);
	set("coor/x", -6080);
	set("coor/y", -1040);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}