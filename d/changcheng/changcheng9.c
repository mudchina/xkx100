// Room: /d/changcheng/changcheng9.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长城");
	set("long", WHT @LONG
这里就是举世闻名的──长城。站在长城上，你可以看到四周群山
环绕，山上可以看见不少矮矮的灌木丛，但不少的树也被砍光了，很多
地方已经露出了一片片的黄土，举目望去，你脚下的长城顺着山脊象一
条巨龙般蜿蜒的向北，向南延伸出去。
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"northdown" :__DIR__"changcheng10",
		"southup"   :__DIR__"changcheng8",
	]));
	set("no_clean_up", 0);
	set("coor/x", -7000);
	set("coor/y", 8000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}