// Room: /d/lingxiao/liao.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG 
这是廖自励的房间。四位长老中，以他最为生性多智，有人说若不
是当年先师仙去时，他不在凌霄城内，而等他回来之时，大局已定，那
这掌门之位必为他囊中之物。这房间内摆满了书，从《孙子兵法》到《
史记》，尽皆是权谋争斗之书。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"zoulang3", 
	]));
	set("objects", ([  
		__DIR__"npc/liao" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

