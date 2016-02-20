// Room: /d/wuxi/sanfengqiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "三凤桥");
	set("long", @LONG
眼前一座单孔拱桥，象一道彩虹跨在南长街上，桥的两侧下方长满
了青苔，深深的水痕显示羊雨季时的水位。桥面上古老的青砖和两旁的
条石都在诉说着它悠久的历史。从桥上看下去，下面是穿越城市的运河
不少画舫在运河中游弋，一到夜幕降临，河水中星星点点，恰似天上的
繁星。喧闹之声从桥的南北两头不断传来。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"south" : __DIR__"southroad2",
		"north" : __DIR__"southroad1",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -820);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}