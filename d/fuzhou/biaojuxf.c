// Room: /city/biaojuxf.c

inherit ROOM;

void create()
{
	set("short", "东厢房");
	set("long", @LONG
房间里布置很简单，只有一张小床，一个小几，和几张方凳。窗台
上放着一个磁杯，杯里插着几枝无名小花。房间虽不大，但是给人整洁
舒适的感觉。
LONG
        );
	set("exits", ([
		"west" : __DIR__"biaojuhy",
	]));
	set("objects", ([
		__DIR__"npc/zhu" : 1,
	]));
	set("coor/x", 1831);
	set("coor/y", -6296);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
