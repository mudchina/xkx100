// Room: /beijing/nandaj2.c

inherit ROOM;

void create()
{
	set("short", "南大街广场");
	set("long", @LONG
这里是一个热闹的广场，正是北京城里最热闹、最杂乱的地段。一
座天桥横跨东西，正是卖杂货、变把戏、跑江湖杂人等聚居的所在。宽
阔的大道向南北两头延伸。南边是永定门，通往郊外；北边是南大街，
通往天安门。东边是有名的“高升茶馆”，人们都爱在那儿休息聊天。
西边有一家很大的屠宰场，不时传来猪凄厉的哀嚎。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"west"  : __DIR__"tuzai",
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"yongding",
		"north" : __DIR__"nandaj1",
	]));
        set("objects", ([
		"/d/baituo/npc/snaker" : 1,
		"/d/taishan/npc/dao-ke" : 1,
		"/d/taishan/npc/jian-ke" : 1,
        ]));
	set("coor/x", -200);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
