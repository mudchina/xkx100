// Room: /d/changcheng/juyongguan.c
// Last Modified by Winder on Aug. 25 2000
#include <ansi.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "居庸关");
	set("long", WHT@LONG
这里就是长城上著名的雄关──居庸关。这里风景优美，满山遍野
的枫树，一到秋天所有的枫叶都变成了红色，把这里变成了一片红色的
海洋。当年，康熙皇帝到这里游玩时，被这美丽的景色吸引，亲笔提下
了“居庸叠翠”四个大字。
    由于从这里向北通向关外广阔无垠的蒙古大草原，向西可以前往西
域，许多从京城逃出来的罪犯都是从这里逃出去，所以城墙上贴满了官
府的告示(gaoshi)，而守卫的官兵也戒备森严，随时盘问着可疑的人。
LONG
NOR  );
	set("outdoors", "changcheng");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west"  : __DIR__"changcheng1",
		"east"  : __DIR__"badaling",
		"north" : "/d/mobei/huanglu1",
		"south" : __DIR__"nroad2",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -190);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n         居庸总兵\n      风城主\n";
}
