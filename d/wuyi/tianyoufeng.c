// Room: /d/wuyi/tianyoufeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "天游峰");
	set("long", @LONG
天游峰位于六曲之北，壁立万仞，高耸群峰之上。每每雨后天晴抑
或晨曦初露之时，山谷弥漫着白茫茫的烟云，气象万千。登巅顶，望云
海，变幻莫测，宛如置身蓬莱仙境，犹如遨游玉阙天宫，故名天游。徐
霞客曰：“其不临溪而能尽九曲之胜，此峰固应第一也。”然也。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"up"        : __DIR__"tianyouguan",
		"eastdown"  : __DIR__"tianyoupath1",
		"northdown" : __DIR__"tianyoupath2",
		"northeast" : __DIR__"xianyutan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -4970);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

