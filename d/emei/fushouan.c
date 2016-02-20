//Room: fushouan.c 福寿庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","福寿庵");
      set("long",@LONG
福寿庵在神水庵南，是一个名叫天性的僧人建造的。庵前有九曲渠、流杯
池，古人曾据在此饮酒流杯，观景赋诗，歌咏兴叹，不知夕日。庵旁有株大海
棠树，数百苍龄，高达十余丈。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/zhen" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "enter"     : __DIR__"lingwenge",
          "north"     : __DIR__"shenshuian",
      ]));
      set("outdoors", "emei");
//      set("no_clean_up", 0);
	set("coor/x", -6100);
	set("coor/y", -1050);
	set("coor/z", 70);
	setup();
      replace_program(ROOM);
}