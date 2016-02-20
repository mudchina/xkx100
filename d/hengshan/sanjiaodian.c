// Room: /d/hengshan/sanjiaodian.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "三教殿");
	set("long", @LONG
这里是全寺最高处的三教殿，也是悬空寺最大的殿宇。三层九脊，
全部由每根插入崖石的木梁承受，真是“公输天巧”，古今奇迹。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"down"   : __DIR__"xuankong1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3180);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
