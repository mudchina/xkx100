// Room: /d/wuxi/northgate.c
// Winder 2000/02/22 

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "莲蓉门");
	set("long", @LONG
北城门叫莲蓉门，从此向北去是就江阴的长江要塞，官府为此将大
道一直修到了江边。因为在要塞处的江面上禁止通船，所以从这里出城
的普通百姓少，和南边热热闹闹的景象组成了明显的反差。城墙上有一
张白纸黑字的官府告示(gaoshi)。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"south"  : __DIR__"northroad2",
		"north"  : __DIR__"lianrongqiao",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 370);
	set("coor/y", -760);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n无锡知府\n晨宜\n";
}