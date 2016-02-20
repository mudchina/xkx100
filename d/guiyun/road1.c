// Room: /d/guiyun/road1.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "湖滨小路");
	set("long", @LONG
一条湖滨的荒野小路，岸堤长满长草，风过处，一阵阵摇头晃脑。
往西边远处看似乎横着一条小河。东边是无锡的泰伯庙。
LONG);
	set("outdoors", "guiyun");
	set("objects",([
		__DIR__"npc/youke" : 1,
	]));  
	set("exits", ([
		"east": "/d/wuxi/taibomiao",
		"west": __DIR__"rivere",
	]) );
	setup();
	replace_program(ROOM);
}

