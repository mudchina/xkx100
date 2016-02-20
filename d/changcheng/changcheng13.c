// Room: /d/changcheng/changcheng13.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长城");
	set("long", WHT @LONG
这里就是举世闻名的──长城。站在长城上，你可以看到山脉连绵
起伏，山上已经很少看到树和灌木丛了。山上大片的地方光秃秃的，很
多地方已经露出了大片的黄土，你脚下的长城蜿蜒的向北，向南延伸出
去。站在这里，你已经可以感到迎面过来的大风中带着不少沙子，而长
城厚厚的城墙也被侵蚀的七零八落，不远处的一段城墙已经倒塌。你只
好向南绕过去。
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"west"  :__DIR__"fenghuotai2-1",
		"north" :__DIR__"changcheng12",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10000);
	set("coor/y", 8000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}