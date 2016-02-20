//Room: fsanzhaitang.c 福寿庵斋堂
//Date: Oct. 2 1997 by That
#include <room.h>
inherit ROOM;

void create()
{
      set("short","福寿庵斋堂");
      set("long",@LONG
这里便是峨嵋福寿庵的斋堂。福寿庵本不大，但由于经常接待其他庵的弟子，
斋堂倒也不小。只见厅内摆满了长长的餐桌和长凳，几位小师太正来回忙碌着布置
素斋。桌上摆了几盆豆腐，花生，青菜以及素鸭等美味素食。北面有一扇门(door)。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "east"    : __DIR__"lingwenge",
          "northup" : __DIR__"fsaxiuxishi",
      ]));
      create_door("northup", "门", "southdown", DOOR_CLOSED);
      set("no_clean_up", 0);
	set("coor/x", -6110);
	set("coor/y", -1060);
	set("coor/z", 70);
	setup();
      replace_program(ROOM);
}