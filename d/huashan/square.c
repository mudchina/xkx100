// square.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是华山派的练武场，场上立着几个木人，东边是兵器库，西边
是个小店。通常有许多华山派弟子在此习武练剑。北边的房屋门上挂着
一块匾，上书「群仙观」，西北方似乎有条小道通往山上。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west"      : __DIR__"shop",
		"east"      : __DIR__"bingqifang",
		"south"     : __DIR__"yunu",
		"north"     : __DIR__"qunxianguan",
		"northwest" : __DIR__"chaopath1",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -860);
	set("coor/y", 200);
	set("coor/z", 120);
	setup();
}
 
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam=(mapping)me->query("family");
	if ((!myfam ||myfam["family_name"] != "华山派") && (dir == "east"))
		return notify_fail("那边是华山派的兵器库，这位" + RANK_D->query_respect(me) + "请止步。\n");
	return ::valid_leave(me, dir);
}
 
