//Room: fsaxiuxishi.c 福寿庵休息室
//Date: Oct. 2 1997 by That
#include <room.h>
inherit ROOM;

void create()
{
      set("short","福寿庵休息室");
      set("long",@LONG
这是福寿庵接待峨嵋女侠们的休息室，峨嵋女弟子回山之前通常在此借宿
一宿，好备足体力上山。房内摆有一张长桌，靠墙设有几张木床。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "southdown" : __DIR__"fsazhaitang",
      ]));
      create_door("southdown", "门", "northup", DOOR_CLOSED);
      set("sleep_room", 1);
      set("no_fight", 1);
      set("no_clean_up", 0);
	set("coor/x", -6110);
	set("coor/y", -1050);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}