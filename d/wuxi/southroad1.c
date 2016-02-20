// Room: /d/wuxi/southroad1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "南长街");
	set("long", @LONG
南长街乃是城里的繁华地段，晚上一派灯红酒绿。笑声、歌声、琴
声、箫声，汇成一片送入了你耳中，你不禁心猿意马。北边是一个热闹
的广场。西边是一家老字号的杂货铺，东边则传出一股诱人的酒肉香气，
那是江南有名的松鹤楼，里面供应的无锡酱排骨更是名闻周边，南边是
江南运河，三凤桥横跨其上。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"south" : __DIR__"sanfengqiao",
		"north" : __DIR__"guangchang",
		"east"  : __DIR__"songhe",
		"west"  : __DIR__"zahuopu",
	]));
	set("objects", ([
			__DIR__"npc/lady1" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -810);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}