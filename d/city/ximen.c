// Room: /city/ximen.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "通泗门");
	set("long", @LONG
通泗门是扬州的西门，青砖砌成。城门前沿着城墙，在护城河边种
着扬柳，因而扬州被称为「绿柳城郭」。几个士兵站在城门口，检查着
过往行人车辆。这里是罪犯逃往西域的必经之地，官兵们戒备森严，动
不动就截住行人盘问。城墙上贴着几张通缉告示(gaoshi)。 
    一条笔直的青石板大道向东西两边延伸。西边是郊外，骑马的、座
轿的、走路的，行人匆匆。东边是城里。往北是一片桃林。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"east"  : __DIR__"tongsijie",
		"west"  : "/d/luoyang/road1",
		"north" : "/d/taohuacun/taohua1",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
		__DIR__"npc/runyu" : 1,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", -100);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}