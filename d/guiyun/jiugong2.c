// Room: /d/guiyun/jiugong2.c
// Last Modified by winder on Jul. 9 2001

#include <ansi.h>
inherit ROOM;
#define HERENO	2

int do_get(string arg);
int do_drop(string arg);
int do_look(string arg);
int do_inv(string arg);

void create()
{
	set("short", "æ≈π¨Ã“ª®’Û");
	set("outdoors", "guiyun");
	set("exits", ([
		"west"  : __DIR__"jiugong1",
		"east"  : __DIR__"jiugong3",
		"south" : __DIR__"jiugong5",
	]));
	setup();
}

#include "jiugong.h"
