// Room: /d/yueyang/shijie1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是龙口东侧的青石阶，连接龙口和山上的朗吟亭。石阶两边茶树
连绵，竹响随人，真是个清幽所在。望山下，洞庭湖水簇拥君山，青碧
一片，十分怡人。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"eastup"   : __DIR__"langyinting",
		"westdown" : __DIR__"longkou",
	]));
	set("coor/x", -1710);
	set("coor/y", 2290);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
