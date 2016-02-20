// Room: /d/wuxi/westgate.c
// Winder 2000/02/22 

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "梁溪门");
	set("long", @LONG
城门的来由是和门外的梁溪河有关，因此梁溪也常常成为无锡的别
称，但老百姓还是习惯叫这西门。城墙上贴着几张通缉告示(gaoshi)。
这里是无锡通向北方的必经之地，官兵们戒备森严，动不动就截住行人
盘问。西边是跨越梁溪河跨溪桥，骑马的、坐轿的、走路的，行色匆匆。
东边是热热闹闹的城里。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west"  : __DIR__"kuaxiqiao",
		"east"  : __DIR__"westroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 340);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n无锡知府\n晨宜\n";
}