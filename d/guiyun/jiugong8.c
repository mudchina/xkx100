// Room: /d/guiyun/jiugong8.c
// Last Modified by winder on Jul. 9 2001

#include <ansi.h>
inherit ROOM;
#define HERENO	8

int do_get(string arg);
int do_drop(string arg);
int do_look(string arg);
int do_inv(string arg);

void create()
{
	set("short", "æ≈π¨Ã“ª®’Û");
	set("outdoors", "guiyun");
	set("exits", ([
		"east"  : __DIR__"jiugong9",
		"west"  : __DIR__"jiugong7",
		"north" : __DIR__"jiugong5",
	]));
	setup();
}

#include "jiugong.h"
