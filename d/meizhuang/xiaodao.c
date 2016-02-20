// /d/meizhuang/xiaodao.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走到这条小路上，前面已经可以隐隐约约看到一座小小的院落的
影子，你可以非常的肯定，琴声就是从这个小院里发出来的，想到立刻
就可以见到大庄主黄钟公了，你不禁一阵紧张。 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north"    : __DIR__"xiaoyuan",
		"westdown" : __DIR__"qhpo",
	]));
	set("outdoors", "meizhuang");
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1440);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
