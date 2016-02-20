// Room: /d/chengdu/nanjie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这里是成都的南大街，双人合抱的梧桐在街边十步一株，青石铺就
的路面打扫得干干净净。因为这里大都进出的是官府的人，又是王府必
经之路，所以不许闲杂人等无事逗留的。东边是成都大衙，西边是个全
城有名的说书场。西北便是名闻天下的青羊宫了。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"      : __DIR__"tidujie",
		"west"      : __DIR__"shuchang",
		"south"     : __DIR__"nanjie",
		"north"     : __DIR__"nanjie1",
		"northwest" : __DIR__"qingyang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

