// /kaifeng/tangjian.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "堂间");
	set("long", @LONG
一间四方的堂间，正中的供桌后还摆着尊残缺的佛像，由于缺了半
个脑袋，加上半身被蜘蛛网罩住了，也看不出原来的模样。一边的柱子
旁打了个地铺，靠墙摆着几个水罐。
LONG);
	set("objects", ([
		__DIR__"npc/oldseng" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"kongdi",
	]));

	setup();
	replace_program(ROOM);
}
