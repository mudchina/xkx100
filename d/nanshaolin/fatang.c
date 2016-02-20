// Room: /d/nanshaolin/fatang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", BLU"法堂"NOR);
	set("long", @LONG
这是一座极大的殿堂，可以同时容纳几百人而绝无问题。这里是寺
中演说佛经，佛法和阪戒集会的场所。殿内整齐的放着一排排的蒲团，
以供听经者打坐之用。
LONG );
	set("exits", ([
		"east"      : __DIR__"huilang5",
		"west"      : __DIR__"huilang1",
		"north"     : __DIR__"kchang",
		"southwest" : __DIR__"jietan3",
		"southeast" : __DIR__"jietan4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6110);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

