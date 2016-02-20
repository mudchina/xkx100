//Room: wdroad.c 大道
//Date: Oct.2.1997 by That

inherit ROOM;

void create()
{
      set("short", "黄土大道");
      set("long", @LONG
你走在一条黄土大道上，不时地有人挂剑跨马匆匆而过。
    东北通向武当。
LONG);
      set("outdoors", "sanbuguan");
      set("exits", ([
          "southwest" : __DIR__"xiaolu1",
          "northeast" : "/d/wudang/sanbuguan",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -3400);
	set("coor/y", 900);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}