// buwei1.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "有所不为轩");
	set("long", @LONG
这是华山掌门岳不群的居所「有所不为轩」，此处是前厅，厅上挂
着「正气堂」三字匾额。厅中很宽敞，却没什么摆设，靠墙放着两把交
椅，这里是岳不群议事、授徒的地方，后面是寝室。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"buwei2",
		"south" : __DIR__"qunxianguan",
		"west"  : __DIR__"garden",
		"east"  : __DIR__"buwei3",
	]));
	set("objects", ([
		 __DIR__"npc/dayou": 1,
		 __DIR__"npc/little_monkey": 1,
	]) );

	set("coor/x", -860);
	set("coor/y", 220);
	set("coor/z", 120);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam=(mapping)me->query("family");
	if ((!myfam ||myfam["family_name"] != "华山派") && dir == "north" &&
		objectp(present("lu dayou", environment(me))))
		return notify_fail("陆大有喝道：后面是家师寝室，这位" + RANK_D->query_respect(me) + "请止步。\n");
	return ::valid_leave(me, dir);
}
 
