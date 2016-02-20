// Room: /d/nanshaolin/slyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", HIY"舍利院"NOR);
	set("long", @LONG
这是一座寂静的小院，院中堆满的劈好的木柴，几名身穿白布僧衣
的僧人正在往来忙碌着。这里是寺中僧人圆寂后，焚化归西的场所。院
落的西面有一道小门。
LONG );
        set("no_fight",1);
	set("outdoors","nanshaolin");
	set("exits", ([
		"east" : __DIR__ "huaishu4",
		"west" : __DIR__ "talin1",
        ]));
        create_door("west", "木门", "east", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", 1790);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

