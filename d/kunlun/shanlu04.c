// Room: /d/kunlun/shanlu04.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "石阶路");
	set("long",@long
走过盘山路，就是一段很平整的石阶山路。前面传来刀剑相碰的声
音，快到了，你不由得加快了脚步，远远望去，似乎是个大广场，围着
不少人在练武。
long);
	set("exits",([
		"southdown" : __DIR__"shanlu03",
		"north"     : __DIR__"guangchang",
		"northwest" : __DIR__"guangchangw",
		"northeast" : __DIR__"guangchange",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40030);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}