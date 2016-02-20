// Room: /d/wuxi/southgate.c
// Winder 2000/02/22 

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "朝京门");
	set("long", @LONG
这是南城门，城门的名称是从古汉之时就传下来了。城墙外就是清
名桥，这里住了不少小商小贩，周围贴满了花花绿绿各行各业的广告，
官府的告示(gaoshi)夹在中间倒也不太显目。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"north"  : __DIR__"southroad2",
		"south"  : __DIR__"qingmingqiao",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 370);
	set("coor/y", -840);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n无锡知府\n晨宜\n";
}