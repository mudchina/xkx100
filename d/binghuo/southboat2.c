// Room: /binghuo/southboat2.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "木筏");
	set("long", @LONG
此木筏是岛上参天古木扎就，竖立主桅副桅，这些木材因生于寒
冰之地，木质致密，硬如铁石。帆布和帆索都用树筋兽皮来编织、搓
结。筏上水腌肉，存贮清水的皮袋皆已具备。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

