// /kaifeng/chufang2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "素斋厨");
	set("long", @LONG
素斋厨的几个大灶烧得正旺，白色的蒸汽在室顶铺了一层灶膛间摆
满了松柴，和尚们很挑剔，说是用这种柴禾煮出的饭菜才去近佛。一边
的桌上摆着一个饭桶。东面有个小门出去。
LONG);
	set("objects", ([
		__DIR__"npc/suzhai" : 1,
		__DIR__"npc/shaohuo" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"chufang",
		"east" : __DIR__"zoulang1",
	]));

	setup();
	replace_program(ROOM);
}
