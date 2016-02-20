//Room: fhs.c 伏虎寺
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","伏虎寺");
      set("long",@LONG
伏虎寺是入山第一大宝刹，隐伏在高大的乔木林间，四周楠木参天，多达
十万余株。伏虎寺气象庄严，规模宏盛，殿堂宽敞，势度巍峨。寺刹虽掩覆于
翠绿浓黛之中，但屋瓦却无一片落叶。出寺西上解脱坡便是观音堂。
LONG);
      set("objects", ([
           __DIR__"npc/boydizi" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "east"    : __DIR__"milin1",
          "westup"  : __DIR__"milin2",
      ]));
      set("outdoors", "emei");
//      set("no_clean_up", 0);
	set("coor/x", -6040);
	set("coor/y", -1040);
	set("coor/z", 10);
	setup();
      replace_program(ROOM);
}