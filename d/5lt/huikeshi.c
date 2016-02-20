// Room: /d/5lt/huikeshi.c
inherit  ROOM;

#include <room.h>


void  create  ()
{
	set  ("short",  "会客室");
	set  ("long",  @LONG
这里是村支部的会客室。室里琳琅满目的锦旗、奖状和荣誉证书，
让你不禁看花了眼。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"north"  :  __DIR__"czoffice",
	]));
	set("objects",  ([
	]));

        create_door("north", "木门", "south", DOOR_CLOSED);
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}
