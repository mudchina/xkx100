// Room: /d/changcheng/changcheng23.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长城");
	set("long", WHT@LONG
这里就是举世闻名的──长城。站在长城上，你可以看到四周群山
环绕，山上到处都是矮矮的灌木丛，举目望去，你脚下的长城顺着山脊
象一条巨龙般蜿蜒的向西南和东南方延伸出去。在这里，你已经能看到
东南方远处的海和一座雄伟的关城了。
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"southeast" :__DIR__"shanhaiguan",
		"southwest" :__DIR__"changcheng22",
	]));
	set("no_clean_up", 0);
	set("coor/x", 4000);
	set("coor/y", 6000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}