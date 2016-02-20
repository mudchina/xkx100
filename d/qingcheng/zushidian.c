// Room: /qingcheng/zushidian.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "祖师殿");
	set("long", @LONG
祖师殿又名真武宫。祖师殿背靠轩辕峰，面向白云溪，十分清
幽。附近轩皇台，相传为黄帝受道处。
LONG );
	set("exits", ([
		"eastup"    : __DIR__"chaoyangdong",
		"southdown" : __DIR__"gulongqiao",
	]));
        set("no_clean_up", 0);
	set("coor/x", -8100);
	set("coor/y", -890);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}