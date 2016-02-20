// Room: /d/songshan/tianzhongge.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "天中阁");
	set("long", @LONG
天中阁是中岳庙的大门，原称黄中阁。庙内有古柏三百余株，金石
碑碣百余座。庙前石翁仲，雕制古朴。南面是嵩山的出口太室阙。
LONG );
	set("outdoors","songshan");
	set("exits", ([
		"north" : __DIR__"chongsheng",
		"south" : __DIR__"taishique",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 710);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
