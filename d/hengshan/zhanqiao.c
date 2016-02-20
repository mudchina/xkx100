// zhanqiao.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "悬空栈桥");
	set("long", @LONG
栈道悬于南北危楼之间，由无数的掾铺成，每节掾宽尺许，九节并
排在一起，每根掾绑在铁索上，上铺木板，长数十丈，下临深渊。山风
呼啸，惊心动魄。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"south"   : __DIR__"xuankong2",
		"north"   : __DIR__"xuankong1",
	]));
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3170);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
