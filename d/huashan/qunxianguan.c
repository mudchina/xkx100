// Room: /d/huashan/qunxianguan.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "群仙观");
	set("long", @LONG
这里是华山派历来之根本重地，墙上挂着华山派历代掌门人的画像，
华山派一切重大礼仪都在这里举行。这里也是华山弟子讲武习剑之地。
北边就是华山掌门岳不群的居所「有所不为轩」。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"south": __DIR__"square",
		"north": __DIR__"buwei1",
	]));
	set("objects", ([
		CLASS_D("huashan") + "/yue-buqun": 1,
	]));

	set("coor/x", -860);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
