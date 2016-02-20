// /d/yixing/clshishi.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
昏暗的石屋没有窗户，乃是长乐帮私设的刑堂及囚室。周围摆放
着几件刑具，墙上有些新旧不一的血痕，令人不寒而栗。室内甚是潮
湿，头顶不时滴下水珠。
LONG );
	set("exits", ([
		"west" : __DIR__"clyongdao",
	]));
	set("objects",([
		__DIR__"npc/cl_zhan" : 1,
	]));
	set("no_clean_up", 0);
	setup();

	replace_program(ROOM);
}
