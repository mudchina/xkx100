// Room: /d/chengdu/gongqiao.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "石拱桥");
	set("long",@LONG
这里充分地显示着天府之国那种独特仅有的风格，园拱形的小桥横
跨纵贯成都的府南河。桥下的流水被浮萍染成爱人的翠绿。偶尔一两只
轻舟划过，带动着河边的莲藕随波而动。往西就可以到南大街了。 
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west"      : __DIR__"nanjie",
		"northeast" : __DIR__"funanhe3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


