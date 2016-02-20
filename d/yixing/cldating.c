// /d/yixing/cldating.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
大厅中一股肃杀威严之气。厅堂极为宽大，能容下数十人之众。只
见四周桌上点着明晃晃的巨烛，正中空着一张虎皮交椅。不时有帮众经
过这里，都是屏息静气地低头走过。。
LONG );

	set("exits", ([
		"out"   : __DIR__"cldamen",
		"north" : __DIR__"clzoulang1",
	]));
	set("objects",([
		__DIR__"npc/cl_bei" : 1,
	]));
	setup();
	replace_program(ROOM);
}
