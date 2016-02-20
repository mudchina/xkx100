// Room: /d/5lt/czoffice.c
inherit  ROOM;

#include <room.h>


void  create  ()
{
	set  ("short",  "村长办公室");
	set  ("long",  @LONG
这里就是村长办公室。不大的房间，却布置得井井有条。看到你进
来，屋里的人都不动声色地望着你。南边有一个门(door)。
LONG);
	set("item_desc", ([
		"door" : "这是一扇精巧的木门。\n",
	]));
	set("exits",  ([  //sizeof()  ==  2
		"south"  :  __DIR__"huikeshi",
		"east"   :  __DIR__"chuandashi",
	]));
	set("objects", ([
		__DIR__"npc/fandog" : 1,
	]));

	create_door("south", "木门", "north", DOOR_CLOSED);
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}
