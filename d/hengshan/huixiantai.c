// Room: /d/hengshan/huixiantai.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "会仙台");
	set("long", @LONG
走出北岳殿，就能看见一个石窟，紧靠在绝壁中凿出的一个小室，
就是会仙台。台上排列群仙雕像，密密麻麻，不能胜数。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"eastdown"  : __DIR__"beiyuedian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 3180);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}

