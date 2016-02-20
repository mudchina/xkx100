//Room: xiaolu1.c 小路
//Date: Oct.2.1997 by That

inherit ROOM;

void create()
{
      set("short", "小路");
      set("long", @LONG
这是四川与湖北的交界。一条静悄悄的小土路，两旁有疏疏落落的农舍耕
田，但路上行人很少，都匆匆赶路。
LONG);
      set("outdoors", "sanbuguan");
      set("exits", ([
          "west"      : __DIR__"xiaolu2",
          "northeast" : __DIR__"wdroad",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -5000);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}