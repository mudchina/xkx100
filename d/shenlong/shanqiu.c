// /d/shenlong/shanqiu 山丘
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山丘");
	set("long", @LONG
这是一片山丘地，地上满是树叶和黄土，由于刚下过雨，地面十分
泥泞，突然，你发现地上有许多蛇虫爬行的痕迹，粗细不均，小的有如
筷子，大的确似车辙，你不由得浑身起了一层鸡皮疙瘩。北面是一片果
园。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"north"     : __DIR__"guoyuan",
		"southwest" : __DIR__"shanlu2",
	]));
	set("snaketype", ({"yinhuan"}));
	setup();
}

#include "snakeroom.h";
