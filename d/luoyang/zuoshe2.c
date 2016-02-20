//  Room:  /d/luoyang/zuoshe2.c
#include <ansi.h>
inherit  ROOM;

void  create  ()
{
	set("short",  "内进");
	set("long",  @LONG
走进内进，见桌椅几榻，无一而非竹制。竹几上摆着一具瑶琴，几
后端坐一妙龄少女，玉手轻拨，曼妙琴声便自手傍轻轻升起。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"       :  __DIR__"zuoshe1",
	]));
	set("objects",  ([
		CLASS_D("heimuya")+"/renyy" : 1,
	]));
	set("coor/x", -382);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}