// Room: /d/changcheng/changcheng5.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长城");
	set("long", WHT @LONG
这里就是举世闻名的──长城。站在长城上，你可以看到四周群山
环绕，山上可以看见不少矮矮的灌木丛，但有的地方已经露出了一片片
的黄土地，举目望去，你脚下的长城顺着山脊象一条巨龙般蜿蜒的向东
和向西延伸出去。从这里向东你隐隐约约可以看到东边似乎有一座很大
的关卡。
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"west"     :__DIR__"changcheng6.c",
		"eastdown" :__DIR__"changcheng4.c",
	]));
	set("no_clean_up", 0);
	set("coor/x", -4000);
	set("coor/y", 5000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}