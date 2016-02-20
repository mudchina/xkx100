// Room: /d/chengdu/gongqiao1.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "石拱桥");
	set("long",@LONG
这里充分地显示着天府之国那种独特仅有的风格，园拱形的小桥横
跨纵贯成都的府南河。桥下的流水被浮萍染成爱人的翠绿。偶尔一两只
轻舟划过，带动着河边的莲藕随波而动。往北就是风雨亭。 
LONG
	);

	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"xiaojie2",
		"north" : __DIR__"fengyuting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


