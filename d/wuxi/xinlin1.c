// Room: /d/wuxi/xinlin1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "杏树林");
	set("long", @LONG
这是一片茂密的杏树林，一走进来，你仿佛迷失了方向。你走着走
着，你忽然发现这里的杏树变稀少了，再向南北看去，那里隐隐约约地
好象有好多人，你只觉得这里的空气有些紧张。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"dayifenduo",
		"south" : __DIR__"eastgate",
		"east"  : __FILE__,
		"west"  : __FILE__,
	]));
	set("coor/x", 400);
	set("coor/y", -750);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

