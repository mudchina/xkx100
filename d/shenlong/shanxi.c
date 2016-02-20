// /d/shenlong/shanxi 山溪
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山溪");
	set("long", @LONG
沿山溪而行，溪水淙淙，草木清新，颇感心旷神怡。往北是山路，
向南眺望，便是一望无际的大海。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"northwest" : __DIR__"shanlu1",
	]));
	set("snaketype", ({"shuishe"}));

	setup();
}

#include "snakeroom.h"

