// Room: /d/wuxi/eastgate.c
// Winder 2000/02/22 

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "熙春门");
	set("long", @LONG
这是无锡的东城门，城门正上方刻着“熙春门”三个楷书大字，城
墙上贴着几张官府告示(gaoshi)。护城河水一刻不停地流着，过了吊桥
便是一条笔直的大道向东方延伸，那是去苏州的驿道，常有驿使的快马
疾驰而过。西边是城里。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"north" : __DIR__"xinlin1",
		"east"  : __DIR__"road1",
		"west"  : __DIR__"eastroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 400);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n无锡知府\n晨宜\n";
}