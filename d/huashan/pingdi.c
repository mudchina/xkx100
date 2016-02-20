// Room: /d/huashan/pingdi.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "山间平地");
	set("long", @LONG
你走在中条山山间平地上。靠东山壁上有一小屋。传闻当年华山玉
女峰剑气两宗大对决，中计败北的剑宗弟子大多隐匿中条山。难道就是
这里？林中冷风轻吹门响。很失意的感觉。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"xiaowu",
		"north" : __DIR__"shangu",
	]));
	set("outdoors", "zhongtiao");
	set("no_clean_up", 0);

	set("coor/x", -930);
	set("coor/y", 170);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
