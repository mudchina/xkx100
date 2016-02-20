// /d/meizhuang/senlin2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "百木园");
	set("long", @LONG
这里是梅庄的百木园，你一走到这里，就象走到了一个连绵无尽的
小森林一样，这里无数的松树，柏树，白杨，还有很多叫不出来名字的
异种苗木，你走在其中，只想把这片树林尽情的欣赏一遍，永不出去才
好。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"senlin3",
		"east"  : __DIR__"senlin6",
		"south" : __DIR__"senlin9",
		"north" : __DIR__"senlin7",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/jiading" : 1,
	]));
	set("outdoors", "meizhuang");

	set("coor/x", 3500);
	set("coor/y", -1430);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
