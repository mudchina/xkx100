// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "侧房");
	set("long", @LONG
这里就是温家老四温方施的住处，据说他在石梁口碑不太好，
主要是好色，你看，他现在正和一个丫鬟在调情。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"zoulang5",
	]));
	set("objects", ([
		__DIR__"npc/wenfangshi" : 1,
		__DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", 1630);
	set("coor/y", -1940);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}