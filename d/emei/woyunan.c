//Room: woyunan.c 卧云庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","卧云庵");
      set("long",@LONG
卧云庵旁边有个井络泉，据说以前曾因饮水人多而干涸，众尼为之诵经，
于是泉水复出。出了卧云庵便是睹光台，旁边是华藏庵。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/xuan" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "out"        : __DIR__"dgtsheshenya",
          "northeast"  : __DIR__"jinding", 
          "southeast"  : __DIR__"huacangan", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6230);
	set("coor/y", -1150);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}