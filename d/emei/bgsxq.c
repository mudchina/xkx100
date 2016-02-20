//Room: bgsxq.c 报国寺西墙
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","西墙");
      set("long",@LONG
这里是峨眉山报国寺的西墙。寺院里的钟声从墙那边飘来，在空气中回
响。一条山溪从西面山上的解脱桥下流经这里，向山下淌去。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "east"      : __DIR__"bgs",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6030);
	set("coor/y", -1030);
	set("coor/z", 10);
	setup();
      replace_program(ROOM);
}