// Room: caolian2 北间操练房
// Date: Sep.30 1997
#include <room.h>

inherit ROOM;

void create()
{
      set("short", "北间操练房");
      set("long", @LONG
这里摆满了大刀长剑、沙袋绑腿等，是武当弟子日常练功的地方。
LONG );

      set("exits", ([ /* sizeof() == 1 */
            "south"   : __DIR__"caolianfang",
      ]));
//      set("no_clean_up", 0);
      set("objects", ([
              "/d/shaolin/npc/mu-ren" : 4,  //四个木人
      ]));
	set("coor/x", -2070);
	set("coor/y", -910);
	set("coor/z", 100);
	setup();
      replace_program(ROOM);
}