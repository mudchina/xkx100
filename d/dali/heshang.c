//Room: /d/dali/heshang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","河上");
	set("long",@LONG
你正身处波涛滚滚的泸水之上百多尺的空中。这是一座乌夷族特
有之藤桥，三根粗大的藤条呈一个倒“品”字形，脚踩下面一条，手
扶左右两条，攀援而过看来惊险，实际上倒也不十分困难。一阵山风
挟着脚下激流飞溅的水花吹过，你感到一阵寒意。
LONG);
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "east"      : __DIR__"cangshanlu1",
	    "west"      : __DIR__"hebian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -46000);
	set("coor/y", -57000);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	if (me->query_dex()<25)
	{
		tell_object(me,"你往藤桥下看了一眼，忽然怕了。\n");
		me->unconcious();
	}
	return 1;
}