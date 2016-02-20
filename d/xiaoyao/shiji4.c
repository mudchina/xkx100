// shiji4.c
// Modified by Winder June.25 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "石级");
	set("long", @LONG
这是一段斜引向上的石级，大概有一百来级吧。缺乏光亮，又转了
三个弯，隐隐听到轰隆轰隆的水声。
LONG );
	set("exits", ([
		"southdown" : __DIR__"fangjian3",
		"eastup"    : __DIR__"shiji5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21010);
	set("coor/z", -30);
	setup();
	replace_program(ROOM);
}