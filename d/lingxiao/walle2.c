// Room: /d/lingxiao/walle2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城头");
	set("long", @LONG 
雪花飘飘。站在这绝高之处，独感天地之悠悠。回思历代帝皇，为
成王图霸业，每每出兵远伐西域。山河辽阔，却是无情战场，江山渺渺，
偏是征人坟地。此情此景，不由令人想起昔人所言：“可怜无定河边骨，
犹是春闺梦里人。”为一人之欲，苦天下之人，古今同矣！
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"east" : __DIR__"walle3",
		"west" : __DIR__"walle1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30980);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

