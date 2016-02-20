// Room: /d/yanping/milin.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
你走在一条僻静的林中官道上，两旁是阴森森的马尾松林。只见左
右前后，到处都是铺天盖地的松树，几十丈高的大松树簇在一块，密实
的松蓬象一柄柄巨帚般伸向天空，把阳光遮得丝毫也无。
LONG );
	set("exits", ([
		"northwest" : __DIR__"guandao3",
		"southeast" : __DIR__"guandao2",
	]));
	set("objects", ([
		__DIR__"npc/jianjingzei" : random(2)+1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1600);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
}

void init()
{
	if (userp(this_player()))
	switch (random(3))
	{
		case 1:
			set("exits", ([
				"northwest" : __DIR__"guandao3",
				"southeast" : __FILE__,
			]));
			break;
		case 2:
			set("exits", ([
				"northwest" : __FILE__,
				"southeast" : __DIR__"guandao2",
			]));
			break;
		default:
			set("exits", ([
				"northwest" : __FILE__,
				"southeast" : __FILE__,
			]));
			break;
	}
	return;
}
