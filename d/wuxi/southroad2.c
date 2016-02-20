// Room: /d/wuxi/southroad2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "南长街");
	set("long", @LONG
南长街上住着许多普通的小市民，里面三教九流的人都有，显得十
分地繁华。青砖铺成的道路向南北两头延伸。西边的吟春书场已有不少
的年头了，是附近的老百姓们最喜欢去的地方了。东边一座两层的楼房
不时地传来阵阵浪笑，那就是这里最有名的群玉院了。北面是跨越运河
的三凤桥。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"sanfengqiao",
		"south" : __DIR__"southgate",
		"east"  : __DIR__"qunyu",
		"west"  : __DIR__"shuchang",
	]));
	set("objects", ([
			__DIR__"npc/lady2" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -830);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}