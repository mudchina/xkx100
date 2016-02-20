// Room: /d/changcheng/changcheng11.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长城");
	set("long", WHT @LONG
这里就是举世闻名的──长城。站在长城上，你可以看到四周群山
环绕，山上的灌木丛已经不象东边的那么多了，树也被砍了不少，很多
地方已经露出了一片片的黄土，举目望去，你脚下的长城顺着山脊象一
条巨龙般蜿蜒的向西，向东延伸出去。向西望去，人烟稀少，让你感到
一片荒凉。
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"west" :__DIR__"changcheng12",
		"east" :__DIR__"changcheng10",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8000);
	set("coor/y", 9000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}