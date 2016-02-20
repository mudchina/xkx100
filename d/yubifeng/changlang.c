// /yubifeng/changlang.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是一条长长的走廊，四处透着浓浓的寒气。出去就是玉笔山庄的
大门，沿这里走过去可以直达大厅，周围一尘不染，非常安静。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"dating",
		"out"   : __DIR__"damen"
	]));
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"npc/xuanmingzi" : 1,
		__DIR__"npc/lingqing" : 1,
		__DIR__"npc/jiang" : 1,
	]));

	set("coor/x", 6120);
	set("coor/y", 5170);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
