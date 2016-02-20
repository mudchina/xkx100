// Room: /city/zuixianlou3.c
// YZC 1995/12/04

inherit ROOM;

void create()
{
	set("short", "醉仙楼三楼");
	set("long", @LONG
这里是三楼，一上来就觉得喧闹无比，和二楼的清雅恰成反比，简
直让你不能相信。几张原本干净整洁的桌子也被糟蹋的一塌糊涂。汤水
淌得满地，酒呃臭屁堆得满屋都是。地上还有残留的血迹。
LONG );
	set("objects", ([
		__DIR__"npc/tao1" : 1,
		__DIR__"npc/tao2" : 1,
		__DIR__"npc/tao3" : 1,
		__DIR__"npc/tao4" : 1,
		__DIR__"npc/tao5" : 1,
		__DIR__"npc/tao6" : 1,
	]));
	set("exits", ([
		"down" : __DIR__"zuixianlou2",
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
