// Room: /d/taohua/neishi1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "落英廊");
	set("long", @LONG
这是一间竹编的通道小间，连接着饭厅和卧室。壁上挂着几张山水
泼墨，手笔极是遒劲，显见出自名家之手。室内很随意地摆着一些小竹
椅，当中围着一张小竹几，几上一壶茶水正香，水气袅袅。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"woshi1",
		"west"  : __DIR__"fanting",
		"south" : __DIR__"zoulang2",
		"north" : __DIR__"neishi2",
	]));
	set("outdoors","taohua");
	set("objects", ([
		__DIR__"npc/yapu" : 1,
	]));

	set("coor/x", 9000);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}